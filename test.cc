/*本程序用于从KLEE生成的测试用例文件中提取具体的值，并依据测试用
例生成执行日志，之后将执行日志转换为etf路径文件*/
#include"Header_File.h"
using namespace std;

struct vartype{
	vector<int> size;
	string type;
};
map<string, string> test_case;                                 //记录提取出的测试用例
vector<string> var_exp;                                        //记录性质中提取出的变量表达式作为命题
unordered_map<string,vector<int>> array_ass;               	   //存储Assumption中提取的前提条件
vector<string> var;                                            //存储性质中提取出的变量
unordered_map<string, string> op;                              //存储性质中的时序运算符与TRACE工具中时序运算符对应关系(需初始化)
map<string, string> var_last_val;                              //记录当前程序中各个变量的最新值,(需要初始化的过程)
map<string,struct vartype> var_type;                           //记录头文件中各个变量名及变量类型
map<string, string> const_var;						   		   //记录变量中可能出现的常量及其值(初始给出)，常量不进行符号化

ifstream property_infile;                                      //待验证性质文件，以规定的形式编写:extract_var()
fstream propos_file;										   //存放从contract中提取中的所有命题
ifstream test_case_infile;                                     //测试用例源文件:read_test_case()        
fstream trace_infile;                                          //GDB生成的程序执行日志:read_trace()
fstream trace_outfile;                                         //转换后的TRACE路径文件
fstream GDB_script;                                            //GDB自动化脚本
fstream src_code_c;                                            //待测IP.c源文件
fstream src_code_h;                                            //待测IP.h头文件
fstream klee_code;                                             //用于KLEE工具生成测试用例的代码文件
fstream init_code;                                             //使用KLEE生成的测试用例初始化后的IP 
fstream z3_contract;										   //contract相关的变量的z3定义文件
fstream z3_constraint;										   //含有量词约束的contract的z3文件
fstream klee_constraint;									   //在使用klee符号化对应数据前人为给出的约束

 
string IP_name = "coolant_basis_5_neg";
//IP代码实现位置
string IP_cpath = "VeriHar-main/sources/" + IP_name + ".c";
//IP头文件位置
string IP_hpath = "VeriHar-main/include/" + IP_name + ".h";
string klee_h_path = "klee-tool-chain/klee/include/klee/klee.h";

string src_path = "";//暂时未使用，指定待验证文件的绝对路径

//是否调用Z3求解器
bool Z3_API = false;												

extract_propos e_p(Z3_API); //该对象用于处理由contract改写的性质文件

/*使用antlr4根据性质提取生成测试用例相关的变量表达式，用于为TRACE生成命题*/
void extract_var(){

	if(IP_name.length() == 0){
		try {
			throw "未指定验证IP名称!";
		}catch (const char* msg) {
			cout << msg << endl;
		}
	}else{

		e_p.get_propos(src_path, IP_name, array_ass, var_exp);
		cout << "---contract文本解析完成---" << endl;
		/*for(int i=0; i<var_exp.size(); ++i){
			cout << var_exp[i] << endl;
		}*/
		
	}
}

/*使用read_test_case函数读出的值，传递给模式切换管理函数执行，并根据断点得到执行日志*/
void generate_execu_log(){
    src_code_c.open(IP_cpath, ios::app|ios::out|ios::in);
    //remove((src_path+"gdb_debug_code.c").c_str());
    init_code.open(src_path+"gdb_debug_code.c", ios::out|ios::app|ios::in);
    init_code<<"#include <string.h>"<<endl;
    while(!src_code_c.eof()){//将IP实现部分拷贝到用于生成执行日志的文件中
        string line;
        getline(src_code_c, line);
        init_code<<line<<endl;    
    }
    //标识源代码的结束，用于后续gdb判断断点位置界限
    init_code<<"//src code end"<<endl;
    string filename = IP_name;//文件名与IP名称，内部结构体名称一致
    init_code<<filename<<" "<<filename<<"1;"<<endl;
    init_code << "int main(){" << endl; 
    init_code<<"\t"<<filename<<"Fun(&"<<filename<<'1'<<");"<<endl;
    init_code<<"\t"<<"// End of call"<<endl;//定位最后一个断点
    init_code<<"\n}"<<endl;//定义main函数，调用IP
    src_code_c.close();
    init_code.close();
    try{
    	src_code_h.open(IP_hpath);
    }catch(...){
    	cout << "IP include file not exist" << endl;
    }
    while(!src_code_h.eof()){
        string line;
        getline(src_code_h, line);
        //该行为变量声明代码
        if((line.find("int")!=string::npos || line.find("oat")!=string::npos) && line.find(";")!=string::npos){
            int type_s, type_e;                //定位变量类型的起止位置
            if(line.find("int")!=string::npos || line.find("oat")!=string::npos){
           
            	type_s = type_e = line.find("int")!=string::npos ? line.find("int") : line.find("oat");
            	while(!isspace(line[type_s])) type_s--;
            	type_s++;
            	while(!isspace(line[type_e])) type_e++;
            	type_e--;
            }
            /*旧功能
            if(line.find("int")!=string::npos){//siint等int型变量
                type_s = line.find("int") - 2; //定位变量类型
                type_e = line.find("int") + 4;
            }else{//float型变量
                type_s = line.find("oat") - 2;
                type_e = line.find("oat") + 4;
            }*/
            int var_s = type_e+2;//定位变量名
            while(line[var_s]==' ' || line[var_s]=='\t') var_s++;
            int var_e = line.find(";") - 1;
            struct vartype vp;
			string var_name = line.substr(var_s, var_e-var_s+1);
            vp.type = line.substr(type_s, type_e-type_s+1);
            if(var_name.find("[")!=string::npos){//数组变量（可能是多维）
            	string temp_name = var_name;
            	while(temp_name.find("[")!=string::npos){
		        	int len = stoi(temp_name.substr(temp_name.find("[")+1,temp_name.find("]")-temp_name.find("[")-1));
		        	vp.size.emplace_back(len);
		        	temp_name = temp_name.substr(temp_name.find("]")+1,temp_name.length()-temp_name.find("]"));
		        }
            }else if(var_name.find('*')!=string::npos && vp.type.find("int")!=string::npos){//指针数组
            	vp.size = array_ass[var_name.substr(1,var_name.length()-1)];
            }else{//非数组变量，大小记为1
            	vp.size.emplace_back(1);
            }
            var_name = line.substr(var_s, var_e-var_s+1);
            var_type[var_name] = vp;
            //该行是后添加的验证辅助变量，无需符号化处理
            if(var_name.find("TEMP_")!=string::npos) continue; 
            //symbolic_var[line.substr(var_s, var_e-var_s+1)] = line.substr(type_s, type_e-type_s+1);
        }
    }
	
	//cout << "var_type = " << var_type.size() << endl;
}

/*根据提取出的变量值，编写GDB自动化脚本，实现运行时监听器*/
void generate_GDB_script(int index){
	
    string filename = IP_name;//提取文件名(无后缀)
    if(index==1){
    	init_code.open(src_path+"gdb_debug_code.c");
		cout << "---生成路径监视器---" << endl;
		GDB_script.open(src_path+"gdb_script.gdb",ios::app|ios::out|ios::in);
		int count_line = 0, count_bp = 0;                         //记录程序读入的行数,设置的断点数
		//string t_com = "set logging file GDB_trace/trace" + to_string(index) +".txt";
		GDB_script << "set logging on" << endl;
		GDB_script << "set print repeats 1000" << endl; //当有大量重复元素时，依然全部显示
		GDB_script << "set $counter = 0" << endl; //设置终止条件变量，counter > 1000 则准备停止, 并设flag = 1
		GDB_script << "set $flag = 0" << endl; //设置终止条件变量，flag = 1 则立刻停止
		GDB_script << "b "<<"gdb_debug_code.c:" << IP_name << "Fun" <<endl;
		for(auto it=var_type.begin(); it!=var_type.end(); it++){//在IP初始结构体中出现的变量使用display关键字即可，未在IP中定义，但在命题中出现的需要单独打印
		    if(it->first.find("*")!=string::npos){//指针或数组类型变量。该类型的变量(指针一般为数组首地址)，可以根据Contract的Assumption初始化
		        string array_name = it->first.substr(1,it->first.length()-1);
		        //不管是几维数组，都使用(display 数组名)的方式打印数组的值
		        if(it->second.type.find("siint")!=string::npos) 	 GDB_script<<"\tdisplay/d "<<array_name<<endl;
		        else if(it->second.type.find("unint")!=string::npos) GDB_script<<"\tdisplay/u "<<array_name<<endl;
		        else if(it->second.type.find("float")!=string::npos) GDB_script<<"\tdisplay/f "<<array_name<<endl;   
		    }else if(it->first.find("[")!=string::npos){//数组型变量
		    	string array_name = it->first.substr(0,it->first.find('['));
		    	if(it->second.type.find("siint")!=string::npos) 	 GDB_script<<"\tdisplay/d "<<filename<<"1."<<array_name<<endl;
		        else if(it->second.type.find("unint")!=string::npos) GDB_script<<"\tdisplay/u "<<filename<<"1."<<array_name<<endl;
		        else if(it->second.type.find("float")!=string::npos) GDB_script<<"\tdisplay/f "<<filename<<"1."<<array_name<<endl;   
		    }else{//
		        if(it->second.type.find("siint")!=string::npos){
		            GDB_script<<"\tdisplay/d "<<it->first<<endl;
		        }else if(it->second.type.find("float")!=string::npos){
		            GDB_script<<"\tdisplay/f "<<it->first<<endl;
		        }else if(it->second.type.find("unint")!=string::npos){
		        	GDB_script<<"\tdisplay/u "<<it->first<<endl;
		        }  
		    }
		}
		vector<string> array;//待打印大小的数组名
		while(!init_code.eof()){
		    string code;
		    getline(init_code, code);
		    if(code.find("src code end")!=string::npos){
		    	count_line++;
		    	while(code.find("End of call")==string::npos){
		    		getline(init_code, code);
		    		count_line++;
		    	}
		    	GDB_script<<"b "<<"gdb_debug_code.c"<<":"<<count_line<<"\n"<<"\tcommands "<<count_bp+1<<endl;
		    	GDB_script<<"\tset $counter = $counter + 1\n" 
							  << "\tif $counter > 1000\n" << "\t\tquit\n" << "\tend" << endl;
				GDB_script<<"\tcontinue"<<"\n"<<"end"<<endl;
		    	break;
		    }
		    count_line++;
		    //该行不需要打断点
		    if(code.find("if")!=string::npos || code.find("else")!=string::npos || code.find("for")!=string::npos || code.length()<5) continue;
		    //该行没有具体操作  
		    if(code.find(" { ")!=string::npos || code.find(" } ")!=string::npos) continue;		
		    //某些结构体变量初始化的过程
		    if(code.find("\t.")!= string::npos || code.find(" .")!= string::npos) continue;      
		    for(auto it=var_type.begin(); it!=var_type.end(); it++){
		    	string var_name;
		    	if(it->first.find('*')!=string::npos) {
		    		if(find(array.begin(),array.end(),it->first)==array.end()) array.push_back(it->first);
		    		var_name = it->first.substr(1,it->first.length()-1);
		    	}
		    	else if(it->first.find('[')!=string::npos){
		    		if(find(array.begin(),array.end(),it->first.substr(0,it->first.find('[')))==array.end()) \
		    			array.push_back(it->first.substr(0,it->first.find('[')));
		    		var_name = it->first.substr(0,it->first.find('['));
		    	} 
		    	else var_name = it->first;
		    	//如果该行代码中存在结构体中定义的变量
		        if(code.find(var_name)!=string::npos){
		        	//修改：需要定义一个程序keyword，如果搜索到则跳过
		            string temp;
		            count_bp++;
		    		GDB_script<<"b "<<"gdb_debug_code.c"<<":"<<count_line<<"\n"<<"\tcommands "<<count_bp<<endl;
					GDB_script<<"\tset $counter = $counter + 1\n" 
							  << "\tif $counter > 1000\n" << "\t\tquit\n" << "\tend" << endl;
					GDB_script<<"\tcontinue"<<"\n"<<"end"<<endl;
		            break;    
		        }   
		    }
		    string flag = filename+"Fun(&"+filename+"1);";
		    if(code.find(flag)!=string::npos && count_bp>0){			//main函数中IP调用为整个测试代码的最后一步
		    	GDB_script<<"b "<<"gdb_debug_code.c"<<":"<<count_line<<"\n"<<"\tcommands "<<count_bp+1<<endl;
		    	GDB_script<<"\tset $counter = $counter + 1\n" 
		    			  << "\tif $counter > 1000\n" << "\t\tquit\n" << "\tend" << endl;
		    	GDB_script<<"\tcontinue"<<"\n"<<"end"<<endl;
		    	break;
		    }
		}
		GDB_script<<"run"<<endl;
		GDB_script.close();
		system("gcc -g gdb_debug_code.c -o gdb_debug_code");
		init_code.close();
    }
    //src_code_c.close();
    
    //以下用于调用GDB去调试上述生成的初始化后的IP，并生成程序执行日志
    
    string t_com = "gdb gdb_debug_code -batch -x gdb_script.gdb > GDB_trace/trace" + to_string(index) +".txt";
    system((t_com).c_str());
    //remove("gdb_debug_code.c");
    //remove("gdb_debug_code");
}

/*计算将命题中的变量替换为执行路径中的实际输出，用于后续判断命题的正误.*/
void judge_proposition(map<string, pair<string, string>> &next, vector<bool> &propos, const bool &first_time, bool &issame){
	//存在量词或未定义函数的命题，调用Z3-Prover判断
	if(Z3_API){
		z3_contract.open(IP_name+".py", ios::app|ios::out|ios::in);
		if (!z3_contract.is_open()) {
			std::cout << "z3-Prover IP_contract file not found!" << std::endl;
			return;
		}
		string propos_file_path = src_path+"IP_"+IP_name+"_propos.txt";
		Z3_Prover_Propos(propos_file,propos_file_path,next,z3_contract,IP_name+".py",z3_constraint,first_time,e_p.z3_propos, propos);
	}
	else{//仅涉及值判断不调用Z3
		vector<bool> n_propos; //存放当前断点出的命题判断结果
		for(int i=0; i<var_exp.size(); ++i){
			string exp = var_exp[i];
			if(exp.length()==0) continue;
			for(auto it=var_last_val.begin(); it!=var_last_val.end(); it++){
				while(exp.find(it->first)!=string::npos){
					if(it->second.find('-') == 0) it->second = "(" + it->second + ")";
				    exp.replace(exp.find(it->first), it->first.length(), it->second);
				    break;
				}    
			}
			if(exp.length()==0) continue;
			if(exist_alpha(exp)) propos.push_back(false);//如果字符串中仍然存在字母，说明存在程序执行路径中不存在的变量
			else propos.push_back(cal_propos_val(exp));
		}
		/*if(!first_time){
			//按位图的方式记录命题与上一断点是否相同，若相同，则无需作为TRACE的新事件
			uint64_t pold = 0, pnew = 0;
			for(int i=0; i<propos.size(); ++i){
				pnew = (pnew << 1) | n_propos[i];
				pold = (pold << 1) | propos[i]; 
			}
			issame = (pold == pnew);
			if(!issame){
				propos.clear();
				propos = n_propos;
			}
		}else{ //第一次无需判断，直接赋值
			issame = false;
			propos = n_propos;
		}*/
	}
	return;
}

/*提取执行日志,并转换为etf路径文件*/
void read_trace(int index){

    string line;
    int num_bp = 0;                                   //通过记录执行日志打印的断点数记录生成的路径长度
    bool last_line = false;                           //用于记录是否读到文件末尾，与next操作符关联
	if(index==1) cout << "---验证TRACE路径模型---" << endl;          
    trace_infile.open(src_path+"GDB_trace/trace" + to_string(index) + ".txt", ios::app|ios::out|ios::in);
    trace_infile<<"[Inferior 1 (process) exited normally]"<<endl;//防止读取时找不到文件末尾
    trace_infile.close();
    trace_infile.open(src_path+"GDB_trace/trace" + to_string(index) + ".txt", ios::app|ios::out|ios::in);
    trace_outfile.open(src_path+"TRACE/TRACE" + to_string(index) + ".etf", ios::app|ios::out|ios::in);
    if (!trace_outfile.is_open())		                        //判断文件是否成功打开
	{
		cout<<"Error opening file:trace.txt"<<endl;
	}
    trace_outfile<<"TU MILLISECONDS\n"<<"R 0 100.0 false;\n";
    map<string, pair<string, string>> next;                                  //first存放当前变量值，second存放下个状态变量值，用于之后比较
    vector<bool> propos; 
    bool first_time = true;
    while(!trace_infile.eof()){         
        getline(trace_infile, line);
        //定位断点的位置，以行开头为数字作为识别标识
        if((line[0]-'0')<10 && (line[0]-'0')>0 && (line.find(':')==string::npos || line.find(':')>3)){      
            getline(trace_infile, line);
            string para_name, para_val;                         //存储参数名，参数值
            while(line.find(":")!=string::npos && line.find("exited")==string::npos){
                if(line.find('=')==string::npos) break;
                int j = line.find("=");
                //辅助记录变量名的位置，对变量名进行简化，去除掉所在的结构体名或者类(也可以根据需要保留)
                if(line.find('.')!=string::npos && line.find(".")<j){
                    int aux1;                                   
                    aux1 = line.find('.');
                    para_name = line.substr(aux1+1, j-aux1-2);
                    para_val = line.substr(j+2, line.length()-(j+2));
                }else{//全局变量
                    int aux2 = line.find(':');
                    if(line.find("/f")!=string::npos || line.find("/d")!=string::npos || line.find("/u")!=string::npos)
                    	para_name = line.substr(aux2+5, j-aux2-6);
                    else
                    	para_name = line.substr(aux2+2, j-aux2-3);
                    para_val = line.substr(j+2, line.length()-(j+2));
                }
                //如果是数组,此时变量名只有数组名，补充一对中括号标识数组
                if(para_val.find('{')!=string::npos){
                	para_name += "[]";
                	while(para_val.find('{')!=string::npos) para_val.replace(para_val.find('{'),1,"[");
                	while(para_val.find('}')!=string::npos) para_val.replace(para_val.find('}'),1,"]");
                } 
                var_last_val[para_name] = para_val;                 //执行日志中最新的变量值存入 
                if(next[para_name].first.empty()){
                    next[para_name].first = para_val;
                }else{
                    next[para_name].second = para_val;
                }
                getline(trace_infile, line);
            }
            bool issame = false; //记录上次命题与该次判断结果是否相同
            /*judge_proposition(next,propos,first_time,issame);
        	if(!issame){
        		trace_outfile<<"C "<<num_bp<<" ";
	            trace_outfile<<fixed<<setprecision(1)<<1.0*num_bp<<" "<<1.0*(num_bp+1)<<" 0 100.0;";//输出活动的定义 
	            for(int j=0; j<propos.size(); j++){
	                trace_outfile<<boolalpha<<"p"<<j+1<<"="<<propos[j];
	                if(j<propos.size()-1) trace_outfile<<",";
	            }
	            trace_outfile<<"\n";
	            num_bp++;
        	}
        	if(line.find("debugging session") != string::npos) break;
            else propos.clear();*/
        	judge_proposition(next,propos,first_time,issame);
    		trace_outfile<<"C "<<num_bp<<" ";
            trace_outfile<<fixed<<setprecision(1)<<1.0*num_bp<<" "<<1.0*(num_bp+1)<<" 0 100.0;";//输出活动的定义 
            for(int j=0; j<propos.size(); j++){
                trace_outfile<<boolalpha<<"p"<<j+1<<"="<<propos[j];
                if(j<propos.size()-1) trace_outfile<<",";
            }
            trace_outfile<<"\n";
            num_bp++;
            if(line.find("debugging session") != string::npos) break;
            else propos.clear();   
            first_time = false; 
        }                                   
    }
    trace_outfile<<"S 0; name = s1\n"<<"F 0 0 "<<1.0*num_bp<<" 1.0 0.0 0.0"<<endl;
    trace_infile.close();
    trace_outfile.close();
    return;
}

bool Verify_TRACE(int index){

	//tracp4cps jar文件位置
	string jar = "trace4cps/temporallogic/org.eclipse.trace4cps.tl.cmd/target/eclipse-trace4cps-incubation-dev/lib/org.eclipse.trace4cps.tl.cmd-0.2.0-SNAPSHOT.jar";
	string spec = "property.etl";
	string TRACE = "TRACE/TRACE";
	
	call_trace4cps c_t(jar,spec,TRACE);
	
	c_t.verify(index);
	
	if(c_t.flag) return true;
	else return false;
}

int main(int argc, char* argv[]){
    
    std::chrono::high_resolution_clock::time_point s1;
    std::chrono::high_resolution_clock::time_point e1;
    std::chrono::high_resolution_clock::time_point s2;
    std::chrono::high_resolution_clock::time_point e2;
    
	clock_t start_time, end_time;
	bool IP_res = true;
    extract_var();
    generate_execu_log();
    for(int i=1; i<=100; ++i){
//s1 = std::chrono::high_resolution_clock::now();
		generate_GDB_script(i);
		init_code.close();
//e1 = std::chrono::high_resolution_clock::now();
//cout << "单条执行路径生成的CPU时间为: " << std::chrono::duration_cast<std::chrono::milliseconds>(e1 - s1).count() << "ms" << endl; 
		read_trace(i);
		var_last_val.clear();
		remove("gdb.txt");
//s2 = std::chrono::high_resolution_clock::now();
		IP_res &= Verify_TRACE(i);
		if(!IP_res) break; 
//e2 = std::chrono::high_resolution_clock::now();
//cout << "单条执行路径验证CPU时间为: " << std::chrono::duration_cast<std::chrono::milliseconds>(e2 - s2).count() << "ms" << endl;                  
    }
    remove("gdb_script.gdb");
    cout << "IP验证结果:" << boolalpha << IP_res << endl;
    remove("gdb_debug_code.c");
    remove("gdb_debug_code");
    return 0;
}
