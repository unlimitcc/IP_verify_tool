/*本程序用于从KLEE生成的测试用例文件中提取具体的值，并依据测试用
例生成执行日志，之后将执行日志转换为etf路径文件*/
#include"Header_File.h"
using namespace std;

struct vartype{
	vector<int> size;
	string type;
};
map<string, string> test_case;                                 //记录提取出的测试用例
vector<string> var_exp;   									   //记录性质中提取出的变量表达式作为命题
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

 
string IP_name = "ModeSwitch";
//IP代码实现位置
string IP_cpath = "VeriHar-main/sources/" + IP_name + ".c";
//IP头文件位置
string IP_hpath = "VeriHar-main/include/" + IP_name + ".h";
string klee_h_path = "klee-tool-chain/klee/include/klee/klee.h";

string src_path = "";//暂时未使用，指定待验证文件的绝对路径

//是否调用Z3求解器
bool Z3_API = false;		

//生成监视器的时间
std::chrono::high_resolution_clock::time_point s2;
std::chrono::high_resolution_clock::time_point e2;
//生成执行路径的时间
std::chrono::high_resolution_clock::time_point s3;
std::chrono::high_resolution_clock::time_point e3;										

extract_propos e_p(Z3_API); //该对象用于处理由contract改写的性质文件

/*使用antlr4根据性质提取生成测试用例相关的变量表达式，用于为TRACE生成命题*/
void extract_var(){

	try {
		if(IP_name.length() == 0){
			throw "<extract_var()>: extrac未指定验证IP名称!";
		}
	}catch (const char* msg) {
		cout << msg << endl;
		exit(1);
	}

	e_p.get_propos(src_path, IP_name, array_ass, var_exp);
	cout << "---contract文本解析完成---" << endl;
	/*for(int i=0; i<var_exp.size(); ++i){
		cout << var_exp[i] << endl;
	}*/
		
}

/*将变量符号化并调用KLEE生成测试用例*/
int KLEE_generate_testcase(){
    src_code_h.open(IP_hpath);
    if(!src_code_h.is_open()){
    	throw runtime_error("<KLEE_generate_testcase()>: \
    						 该IP指定的源码.h文件无法打开或错误，IP名称 : " + IP_name);
    }
    //待符号化的变量<变量名，变量类型> 
    map<string, string> symbolic_var;
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
            symbolic_var[line.substr(var_s, var_e-var_s+1)] = line.substr(type_s, type_e-type_s+1);
        }
    }
    /*所需符号化的变量目前共有以下几类：
	指针类型：多为数组指针，一般在Contract中声明了初始长度(默认按照数组指针处理，特殊情况单独处理)
	普通变量类型：浮点型，整型
	数组类型：可能包括多维数组
    */
    klee_code.open(src_path+"klee_code.c", ios::app|ios::out|ios::in);
    src_code_c.open(IP_cpath);
    if(!src_code_c.is_open()){
    	throw runtime_error("<KLEE_generate_testcase()>: \
    						 该IP指定的源码.c文件无法打开或错误，IP名称 : " + IP_name);
    }
    klee_code<<"#include \""<<klee_h_path<<"\"\n"<<"#include <string.h>"<<endl;
    while(!src_code_c.eof()){
        string line;
        getline(src_code_c, line);
        klee_code<<line<<endl;
    }
    string filename = IP_name;
    //如果const_var中有数组，作为全局数组变量输出
   	for(auto it=const_var.begin(); it!=const_var.end(); it++){
   		if(it->first.find('[')==string::npos) continue;
   		if(it->first.find('*')!=string::npos){//指针形式表示的数组
   			klee_code<<symbolic_var[it->first.substr(0,it->first.find('['))]<<" "<<it->first.substr(1,it->first.length()-1)<<"="<<it->second<<endl;
   		}else if(symbolic_var.find(it->first)!=symbolic_var.end()){//数组形式表示   				
   			klee_code<<symbolic_var[it->first]<<" "<<it->first<<"="<<it->second<<endl;
   		}
   	}
    klee_code<<"int main(){"<<endl;
    int count = 0;//辅助变量，用于符号化变量使用
    klee_code<<"\t"<<filename<<" "<<filename<<"1;"<<endl;//定义结构体
    for(auto it=symbolic_var.begin(); it!=symbolic_var.end(); it++){
    	//输入端口中的常量,浮点数提前生成，存入const_var中直接赋值给对应变量(结构体中的浮点数组不以此方式初始化)
        /*if(const_var.find(it->first)!=const_var.end() && it->first.find('[')==string::npos){//普通浮点数
    		klee_code<<"\t"<<filename<<"1."<<it->first<<"="<<const_var[it->first]<<";"<<endl;
    		continue;
    	}else if(const_var.find(it->first)!=const_var.end()){//const_var中的浮点型数组直接复制给结构体中对应的数组
    		string const_array = it->first.substr(0,it->first.find('['));
    		klee_code<<"\tmemcpy("<<filename<<"1."<<const_array<<","<<const_array<<","<<"sizeof("<<const_array<<"));"<<endl;
    		continue;
    	}else if(it->first.find('*')!=string::npos && it->second.find("float")!=string::npos){//浮点指针数组
    		for(auto p=const_var.begin(); p!=const_var.end(); p++){
    			if(p->first.find(it->first)!=string::npos){
    				string p_array = it->first.substr(1,it->first.length()-1);
    				klee_code<<"\t"<<filename<<"1."<<p_array<<"="<<p_array<<";"<<endl;
    			}
    		}
    	}*/
    	//指针数组符号化
        if(it->first.find('*')!=string::npos){
            klee_code<<"\t"<<it->second<<" "<<it->first.substr(1,it->first.length()-1);
            for(int i=0; i<array_ass[it->first.substr(1,it->first.length()-1)].size(); i++){
                klee_code<<'['<<array_ass[it->first.substr(1,it->first.length()-1)][i]<<']';
            }
            klee_code<<";"<<endl;
            klee_code<<"\t"<<filename<<"1."<<it->first.substr(1,it->first.length()-1)<<"=&"<<it->first.substr(1,it->first.length()-1);
            for(int i=0; i<array_ass[it->first.substr(1,it->first.length()-1)].size(); i++){
                klee_code<<"[0]";
            }
            klee_code<<";"<<endl;
            //样例:"klee_make_symbolic(&pbuff[0], sizeof(pbuff), "*pbuff[19]");"
            klee_code<<"\tklee_make_symbolic(&"<<it->first.substr(1,it->first.length()-1)<<"[0], sizeof("<<it->first.substr(1,it->first.length()-1)<<"), \""<<it->first;
            for(int i=0; i<array_ass[it->first.substr(1,it->first.length()-1)].size(); i++){
                klee_code<<'['<<array_ass[it->first.substr(1,it->first.length()-1)][i]<<']';
            }
            klee_code<<"\");"<<endl;
            //生成的数组测试用例可能为全0,从而无法判断contract的正确性，添加非0约束(非必须，针对代码分析)  
        }else if(it->first.find('[')!=string::npos){//数组符号化,通过memcpy传递给结构体中的数组
            	string array_name = it->first.substr(0,it->first.find('['));//使用原数组名加"1"表示临时数组。例如原结构体中数组为ARRAY[10],临时数组为ARRAY1[10]
            	klee_code<<"\t"<<it->second<<" "<<array_name<<"1"<<it->first.substr(it->first.find('['),it->first.length()-it->first.find('['))<<";"<<endl;
            	klee_code<<"\tklee_make_symbolic("<<array_name<<"1,sizeof("<<array_name<<"1"<<"),\""<<it->first<<"\");"<<endl;
            	klee_code<<"\tmemcpy("<<filename<<"1."<<array_name<<","<<array_name<<"1,sizeof("<<array_name<<"1"<<"));"<<endl;
        }else{//普通变量符号化
            klee_code<<"\t"<<it->second<<"* "<<"p"<<count<<";\n\t"<<it->second<<" "<<"p"<<count+1<<";\n";
            klee_code<<"\tp"<<count<<"= &"<<filename<<"1."<<it->first<<";\n";
            klee_code<<"\tklee_make_symbolic(&p"<<count+1<<", sizeof(p"<<count+1<<"), \""<<it->first<<"\");\n";
            klee_code<<"\tmemcpy(p"<<count<<", &p"<<count+1<<", sizeof("<<filename<<"1."<<it->first<<"));\n";
            count += 2;
        }       
    }
    klee_constraint.open("klee_constraint.txt",ios::out | ios::app | ios::in);
    while(!klee_constraint.eof()){
    	string line;
    	getline(klee_constraint,line);
    	klee_code<<"\t"<<line<<endl;
    }
    klee_constraint.close();
    klee_code<<"\t"<<filename<<"Fun(&"<<filename<<"1"<<");"<<endl;
    klee_code<<"}"<<endl;
    src_code_c.close();
    src_code_h.close();
	cout << "---生成测试用例---" <<endl;
    system("clang -I klee-tool-chain/klee/include -emit-llvm -c -g klee_code.c");//注意klee/klee.h头文件的存放位置
    int ret = system("klee --max-time=60s --only-output-states-covering-new klee_code.bc");//最长运算时间不超过60s
  
    if(ret){
    	cerr << "KLEE生成测试用例失败" << std::endl;
    	exit(EXIT_FAILURE);
    }
    //system("klee --max-time=60s klee_code.bc");//最长运算时间不超过60s
    int num = get_testcasenum(src_path+"klee-last");
    //将所有的测试用例保存
    for(int i=1; i<=num; i++){
    	    string num_i = to_string(i);
    	    stringstream ss;
    	    ss<<setw(6)<<setfill('0')<<num_i;
    	    string num_s;
    	    ss>>num_s;
	    string com = "ktest-tool klee-last/test"+num_s+".ktest > "+src_path+"testcase/testcase_in" + num_i + ".txt";
	    system(com.c_str());
    }
    remove("klee_code.c");
    remove("klee_code.bc");
    return num; 
}

/*提取测试用例实际值的函数*/
void read_test_case(int index){                               

    test_case.clear();  
    //定位变量名
    int begin_name = 0, end_name = 0; 
    //定位变量值起始位置                     	
    int begin_val = 0;                         				
    string line;                                            //记录文件中的一行
    string icom = src_path+"testcase/testcase_in" + to_string(index) + ".txt";
    test_case_infile.open(icom.c_str());
    if (!test_case_infile.is_open())		               	//判断文件是否成功打开
	{
		throw runtime_error("<read_test_case()>: \
    						 读取测试用例文件 [testcase_in" + to_string(index) + ".txt] 发生错误");
	}
    string NAME, VAL;                                 		//NAME, VAL分别记录变量名，变量值
    while(!test_case_infile.eof()){
        getline(test_case_infile, line);                    //获取文件中单行数据
        if(line.find("name")!=string::npos){                     	//输出变量名
            begin_name = line.find("name") + 7;                                //从“name”到变量名第一个字符距离为7个字符(固定)
            end_name = line.find("'", begin_name+1);
            NAME = line.substr(begin_name,(end_name-begin_name));
            //真正的变量名var_id,仅当出现指针数组时启用
            string var_id;
            if(NAME.find('*')!=string::npos && NAME.find('[')!=string::npos) var_id = NAME.substr(0,NAME.find('['));
            else var_id = NAME;
            //指针及普通整形数组，具体值保存在"hex:"段，指针数组的大小是人为定义的，原定义中没有
            if(NAME.find('[')!=string::npos && var_type[var_id].type.find("int")!=string::npos){
                while(line.find("hex")==string::npos) getline(test_case_infile, line);
				begin_val = line.find("hex") + 8;
			    VAL = line.substr(begin_val, (line.length()-begin_val));
			    //KLEE测试用例hex均为小端存储
			    int len;			//数组中单个数据的大小，单位:byte
			    bool sign = false;	//是否是有符号数,有符号:true
			    if(var_type[var_id].type.find("unint08")!=string::npos){
			    	len = 1;
			    }else if(var_type[var_id].type.find("siint08")!=string::npos){
			    	len = 1;
			    	sign = true;
			    }else if(var_type[var_id].type.find("unint16")!=string::npos){
			    	len = 2;
			    }else if(var_type[var_id].type.find("siint16")!=string::npos){
			    	len = 2;
			    	sign = true;
			    }else if(var_type[var_id].type.find("unint32")!=string::npos){
			    	len = 4;
			    }else if(var_type[var_id].type.find("siint32")!=string::npos){
			    	len = 4;
			    	sign = true;
			    }
				for(int i=0; i<VAL.length();){
					int temp_len = len;
					string temp;
					while(temp_len>0){
						temp.insert(0,VAL.substr(i,2));
						i += 2;
						temp_len -= 1;
					}
				    //var_last_val[name] = val;
				    temp = sign?to_string((int)stoi(temp,nullptr,16)):to_string((int)stoul(temp,nullptr,16));
				    test_case[NAME] += temp;
				    if(i+len<VAL.length()) test_case[NAME] += ',';
				}
            }
            //浮点型数据，数值保存在hex段
            else if((NAME.find('*')!=string::npos && NAME.find('[')!=string::npos) || var_type[var_id].type.find("float")!=string::npos){
	    		while(line.find("hex")==string::npos) getline(test_case_infile, line);
	    		begin_val = line.find("hex") + 8;//去掉0x部分
	    		VAL = line.substr(begin_val,(line.length()-begin_val));
    			if(var_type[var_id].type.find("float32")!=string::npos){
    				extract_float(VAL,test_case,NAME);
    			}else{
    				extract_double(VAL,test_case,NAME);
    			}
            }else{
            	//测试用例中的普通整型变量
            	if(var_type[var_id].type.find("unint")!=string::npos){
            		while(line.find("uint")==string::npos) getline(test_case_infile, line);
            		begin_val = line.find("uint") + 6;
            	}else{
            		while(line.find(" int")==string::npos) getline(test_case_infile, line);
            		begin_val = line.find(" int") + 6;
            	}
            	VAL = line.substr(begin_val,(line.length()-begin_val));
            	test_case[NAME] = VAL;
            	var_last_val[NAME] = VAL;	
            }
            begin_name = 0;                    
        }                                              
    }
    test_case_infile.close();
    return;
}

/*使用read_test_case函数读出的值，传递给模式切换管理函数执行，并根据断点得到执行日志*/
void generate_execu_log(){
    src_code_c.open(IP_cpath, ios::app|ios::out|ios::in);
    remove((src_path+"gdb_debug_code.c").c_str());
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
    string temp[100], array_name;
    vector<string> array;
    //利用生成的测试用例初始化结构体中的数据，结构体名为“IP(IP名称)1”，例如“Fg333saCheck1”
    init_code<<filename<<" "<<filename<<"1={"<<endl;
    init_code<<"\t.fun="<<filename<<"Fun,"<<endl;
    init_code<<"};\n"<<endl;//结构体初始化完成
    //测试用例中有指针数组，先打印数组作为全局变量，再将头指针赋给结构体中的对应元素
    for(auto it=test_case.begin(); it!=test_case.end(); it++){
     	if(it->first.find('*')!=string::npos){	
     		init_code<<var_type[it->first.substr(0,it->first.find('['))].type<<" "<<it->first.substr(1,it->first.length()-1)<<"={"<<it->second<<"};"<<endl;
     	}
    }
    init_code << "int main(){" << endl; 
    //初始化生成测试用例的变量
    for(auto it=test_case.begin(); it!=test_case.end(); it++){
    	//测试用例中有指针数组，先打印数组，再将头指针赋给结构体中的对应元素
     	if(it->first.find('*')!=string::npos){	
     		init_code<<"\t"<<filename<<"1."<<it->first.substr(1,it->first.find('[')-1)<<"=&"<<it->first.substr(1,it->first.find('[')-1);
     		for(int i=0; i<array_ass[it->first.substr(1,it->first.find('[')-1)].size(); i++){
                init_code<<"[0]";
            }
     		init_code<<";"<<endl;
     	}//测试用例中有数组，先打印数组，再将数组复制给结构体中对应数组
     	else if(it->first.find("[")!=string::npos && it->first.find('*')==string::npos){
     		string array_name = it->first.substr(0,it->first.find('['));
		    init_code<<"\t"<<var_type[it->first].type<<" "<<it->first<<"={"<<test_case[it->first]<<"};"<<endl;
		    init_code<<"\tmemcpy("<<filename<<"1."<<array_name<<","<<array_name<<","<<"sizeof("<<array_name<<"));"<<endl;
     	}
     	else{
     		init_code<<"\t"<<filename<<"1."<<it->first<<"="<<it->second<<";"<<endl;
     	} 
    }
    for(auto it=const_var.begin(); it!=const_var.end(); it++){//初始化常数或结构体中的浮点变量
    	if(it->first.find('*')!=string::npos || it->first.find("[")!=string::npos) continue;
    	init_code<<"\t."<<it->first<<"="<<it->second<<","<<endl;
    }
    //关于const_var中的数组，单独在main函数中处理，直接通过复制的形式传递给结构体中的对应数组
    for(auto it=const_var.begin(); it!=const_var.end(); it++){//初始化结构体中非指针型浮点数组
    	if(it->first.find('*')!=string::npos || it->first.find('[')==string::npos) continue;//指针数组之前已经初始化过了
    	string const_array = it->first.substr(0,it->first.find('['));
    	init_code<<"\tmemcpy("<<filename<<"1."<<const_array<<","<<const_array<<","<<"sizeof("<<const_array<<"));"<<endl;
    }
    init_code<<"\t"<<filename<<"Fun(&"<<filename<<'1'<<");"<<endl;
    init_code<<"\t"<<"// End of call"<<endl;//定位最后一个断点
    init_code<<"\n}"<<endl;//定义main函数，调用IP
    src_code_c.close();
    init_code.close();
}

/*根据提取出的变量值，编写GDB自动化脚本，实现运行时监听器*/
void generate_GDB_script(int index){
    string filename = IP_name;//提取文件名(无后缀)
    init_code.open(src_path+"gdb_debug_code.c");
    if(!init_code.is_open()){
    	throw runtime_error("<generate_execu_log()>: \
    						 用于生成执行路径的初始化代码 [gdb_debug_code.c] 不存在或错误");
    }
    if(index==1){
    	//生成执行监视器的时间
		s2 = std::chrono::high_resolution_clock::now();
		cout << "---生成路径监视器---" << endl;
		GDB_script.open(src_path+"gdb_script.gdb",ios::app|ios::out|ios::in);
		int count_line = 0, count_bp = 0;                       //记录程序读入的行数,设置的断点数
		//string t_com = "set logging file GDB_trace/trace" + to_string(index) +".txt";
		GDB_script << "set logging on" << endl;
		GDB_script << "set print repeats 1000" << endl; 		//当有大量元素重复时，依然全部显示
		GDB_script << "b "<<"gdb_debug_code.c:" << IP_name << "Fun" <<endl;
		for(auto it=var_type.begin(); it!=var_type.end(); it++){//在IP初始结构体中出现的变量使用display关键字即可，未在IP中定义，但在命题中出现的需要单独打印
		    if(it->first.find("*")!=string::npos){				//指针或数组类型变量。该类型的变量(指针一般为数组首地址)，可以根据Contract的Assumption初始化
		        string array_name = it->first.substr(1,it->first.length()-1);
		        //不管是几维数组，都使用(display 数组名)的方式打印数组的值
		        if(it->second.type.find("siint")!=string::npos) 	 GDB_script<<"\tdisplay/d "<<array_name<<endl;
		        else if(it->second.type.find("unint")!=string::npos) GDB_script<<"\tdisplay/u "<<array_name<<endl;
		        else if(it->second.type.find("float")!=string::npos) GDB_script<<"\tdisplay/f "<<array_name<<endl;   
		    }else if(it->first.find("[")!=string::npos){		//数组型变量
		    	string array_name = it->first.substr(0,it->first.find('['));
		    	if(it->second.type.find("siint")!=string::npos) 	 GDB_script<<"\tdisplay/d "<<filename<<"1."<<array_name<<endl;
		        else if(it->second.type.find("unint")!=string::npos) GDB_script<<"\tdisplay/u "<<filename<<"1."<<array_name<<endl;
		        else if(it->second.type.find("float")!=string::npos) GDB_script<<"\tdisplay/f "<<filename<<"1."<<array_name<<endl;   
		    }else{//
		        if(it->second.type.find("siint")!=string::npos){
		            GDB_script<<"\tdisplay/d "<<filename<<"1."<<it->first<<endl;
		        }else if(it->second.type.find("float")!=string::npos){
		            GDB_script<<"\tdisplay/f "<<filename<<"1."<<it->first<<endl;
		        }else if(it->second.type.find("unint")!=string::npos){
		        	GDB_script<<"\tdisplay/u "<<filename<<"1."<<it->first<<endl;
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
		    	GDB_script<<"\tcontinue"<<"\n"<<"end"<<endl;
		    	break;
		    };
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
		    		GDB_script<<"b "<<"gdb_debug_code.c"<<":"<<count_line+1<<"\n"<<"\tcommands "<<count_bp<<endl;
		            GDB_script<<"\tcontinue"<<"\n"<<"end"<<endl;
		            break;    
		        }   
		    }
		    string flag = filename+"Fun(&"+filename+"1);";
		    if(code.find(flag)!=string::npos && count_bp>0){			//main函数中IP调用为整个测试代码的最后一步
		    	GDB_script<<"b "<<"gdb_debug_code.c"<<":"<<count_line<<"\n"<<"\tcommands "<<count_bp+1<<endl;
		    	GDB_script<<"\tcontinue"<<"\n"<<"end"<<endl;
		    	break;
		    }
		}
		GDB_script<<"run"<<endl;
		GDB_script.close();
		e2 = std::chrono::high_resolution_clock::now();
		cout << "路径监视器生成时间为: " << std::chrono::duration_cast<std::chrono::milliseconds>(e2 - s2).count() << "ms\n";
    }
    //src_code_c.close();
    init_code.close();
    //生成执行路径的时间
    if(index == 1) s3 = std::chrono::high_resolution_clock::now();
    
    //以下用于调用GDB去调试上述生成的初始化后的IP，并生成程序执行日志
    system("gcc -g gdb_debug_code.c -o gdb_debug_code");
    string t_com = "gdb gdb_debug_code -batch -x gdb_script.gdb > GDB_trace/trace" + to_string(index) +".txt";
    system((t_com).c_str());
    //remove("gdb_debug_code.c");
    remove("gdb_debug_code");
    if(index == 40){
    	e3 = std::chrono::high_resolution_clock::now();
    	cout << "执行路径生成时间为: " << std::chrono::duration_cast<std::chrono::milliseconds>(e3 - s3).count() << "ms\n";
    }
}

/*计算将命题中的变量替换为执行路径中的实际输出，用于后续判断命题的正误.*/
void judge_proposition(map<string, pair<string, string>> &next,vector<bool> &propos, const bool &first_time, int &index){
	//存在量词或未定义函数的命题，调用Z3-Prover判断
	if(Z3_API){
		z3_contract.open(IP_name+".py", ios::app|ios::out|ios::in);
		if (!z3_contract.is_open()) {
			throw runtime_error("<judge_proposition()>: \
    						 	  z3-Prover IP_contract 文件未定义!");
			return;
		}
		string propos_file_path = src_path+"IP_"+IP_name+"_propos.txt";
		Z3_Prover_Propos(propos_file,propos_file_path,next,z3_contract,IP_name+".py",z3_constraint,first_time,e_p.z3_propos, propos);
	}
	else{//仅涉及值判断不调用Z3，先处理所有含next的命题
		if(index == 1){
			e_p.get_propos_next(next, var_exp);
		}
		for(int i=0; i<var_exp.size(); i++){
			string exp = var_exp[i];
			if(exp.length()==0) continue;
			for(auto it=next.begin(); it!=next.end(); it++){
				while(exp.find("next("+it->first)!=string::npos && e_p.ex_next[it->first]){//命题中存在next(var)此类表达式，next(var) = 最新值,var = 起始值
					if(it->second.second.length()!=0) exp.replace(exp.find("next("+it->first),it->first.length()+6,it->second.second);//最新值
					else exp.replace(exp.find("next("+it->first),it->first.length()+6,it->second.first);
				}
				while(exp.find(it->first)!=string::npos && e_p.ex_next[it->first]){//命题中存在next(var)此类表达式
					exp.replace(exp.find(it->first),it->first.length(),it->second.first);//修改为该变量的起始值
				}
			}
			for(auto it=var_last_val.begin(); it!=var_last_val.end(); it++){
				while(exp.find(it->first)!=string::npos){
				    exp.replace(exp.find(it->first), it->first.length(), it->second);
				}    
			}
			if(exp.length()==0) continue;
			if(exist_alpha(exp)) propos[i] = false;//如果字符串中仍然存在字母，说明存在程序执行路径中不存在的变量
			else propos[i] = cal_propos_val(exp);
		}
	}
	return;
}

/*提取执行日志,并转换为etf路径文件*/
void read_trace(int index){

    string line;
    int num_bp = 0;                                   //通过记录执行日志打印的断点数记录生成的路径长度
    bool last_line = false;                           //用于记录是否读到文件末尾，与next操作符关联
	if(index==1) cout << "---生成TRACE路径模型---" << endl;          
    trace_infile.open(src_path+"GDB_trace/trace" + to_string(index) + ".txt", ios::app|ios::out|ios::in);
    if(!trace_infile.is_open()){
    	throw runtime_error("<read_trace()>: \
    						 程序执行路径文件 [trace" + to_string(index) + "] 错误！");
    }
    trace_infile<<"[Inferior 1 (process) exited normally]"<<endl;//防止读取时找不到文件末尾
    trace_infile.close();
    trace_infile.open(src_path+"GDB_trace/trace" + to_string(index) + ".txt", ios::app|ios::out|ios::in);
    trace_outfile.open(src_path+"TRACE/TRACE" + to_string(index) + ".etf", ios::app|ios::out|ios::in);
    trace_outfile<<"TU MILLISECONDS\n"<<"R 0 100.0 false;\n";
    map<string, pair<string, string>> next;                                  //first存放当前变量值，second存放下个状态变量值，用于之后比较
    vector<bool> propos(var_exp.size(),0); 
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
            judge_proposition(next, propos,first_time,index);
	        trace_outfile<<"C "<<num_bp<<" ";
	        trace_outfile<<fixed<<setprecision(1)<<1.0*num_bp<<" "<<1.0*(num_bp+1)<<" 0 100.0;";//输出活动的定义  
	        for(int j=0; j<propos.size(); j++){
	            trace_outfile<<boolalpha<<"p"<<j+1<<"="<<propos[j];
	            if(j<propos.size()-1) trace_outfile<<",";
	        }
	        trace_outfile<<"\n";
	        num_bp++;
	        //trace文件的结束标志
	        if(line.find("exited") != string::npos) break;
	        else propos.resize(var_exp.size(),0); 
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
	const string jar = "trace4cps/temporallogic/org.eclipse.trace4cps.tl.cmd/target/eclipse-trace4cps-incubation-dev/lib/org.eclipse.trace4cps.tl.cmd-0.2.0-SNAPSHOT.jar";
	const string spec = "property.etl";
	const string TRACE = "TRACE/TRACE";
	
	call_trace4cps c_t(jar,spec,TRACE);
	
	c_t.verify(index, Z3_API);
	
	if(c_t.flag) return true;
	else return false;
}

int main(int argc, char* argv[]){
    
    //生成测试用例的时间
	std::chrono::high_resolution_clock::time_point s1;
    std::chrono::high_resolution_clock::time_point e1;
    //转换为TRACE模型的时间
    std::chrono::high_resolution_clock::time_point s4;
    std::chrono::high_resolution_clock::time_point e4;
	bool IP_res = true;
    extract_var();
    s1 = std::chrono::high_resolution_clock::now();
    int count = KLEE_generate_testcase();
    e1 = std::chrono::high_resolution_clock::now();
    cout << "测试用例生成时间为: " << std::chrono::duration_cast<std::chrono::milliseconds>(e1 - s1).count() << "ms\n";
    for(int i=1; i<=count; i++){
		read_test_case(i);
		generate_execu_log();
		generate_GDB_script(i);
		init_code.close();
		//read_trace(i);
		var_last_val.clear();
		remove("gdb.txt");
		//IP_res &= Verify_TRACE(i);
		//if(!IP_res) break;                    
    }
    //测试
    s4 = std::chrono::high_resolution_clock::now();
    for(int i=1; i<count; ++i){
    	read_trace(i);
    }
    e4 = std::chrono::high_resolution_clock::now();
    remove("gdb_script.gdb");
    std::cout << "转换为TRACE模型的时间为:" << std::chrono::duration_cast<std::chrono::milliseconds>(e4 - s4).count() << "ms\n";
    //ed = std::chrono::high_resolution_clock::now();
    //cout << "性质验证结果:" << boolalpha << IP_res << endl;
    //std::cout << "耗时为:" << std::chrono::duration_cast<std::chrono::milliseconds>(ed - st).count() << "ms\n";
    return 0;
}
