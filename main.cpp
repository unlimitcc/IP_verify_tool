/*本程序用于从KLEE生成的测试用例文件中提取具体的值，并依据测试用
例生成执行日志，之后将执行日志转换为etf路径文件*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <map>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
#include <float.h>
#include <sstream>
#include <thread>
#include <future>
#include <chrono>
#include <time.h>
#include "Database.h"
#include "aux_fun.h"
#include "/usr/include/python3.10/Python.h"

using namespace std;

typedef unsigned long unint32;
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
fstream TRACE_property;                                        //TRACE工具性质文件
ifstream test_case_infile;                                     //测试用例源文件:read_test_case()        
fstream trace_infile;                                          //GDB生成的程序执行日志:read_trace()
fstream trace_outfile;                                         //转换后的TRACE路径文件
fstream GDB_script;                                            //GDB自动化脚本
fstream src_code_c;                                            //待测IP.c源文件
fstream src_code_h;                                            //待测IP.h头文件
fstream klee_code;                                             //用于KLEE工具生成测试用例的代码文件
fstream init_code;                                             //使用KLEE生成的测试用例初始化后的IP 
fstream z3_contract;										   //含有量词约束的contract的z3文件

string IP_cpath = "/home/rotatecc/desktop/VeriHar-main/sources/ThrusterCtrlLogic.c";
string IP_hpath = "/home/rotatecc/desktop/VeriHar-main/include/ThrusterCtrlLogic.h";
string IP_name = "ThrusterCtrlLogic";
string src_path = "/home/rotatecc/desktop/IP_verify/";

/*使用antlr4根据性质提取生成测试用例相关的变量表达式，用于为TRACE生成命题*/
void extract_var(){
    string infile = src_path+"IP_"+IP_name+"_property.txt";
    propos_file.open(src_path+"IP_"+IP_name+"_propos.txt", ios::app|ios::out|ios::in);
    int count = 0;
    vector<string> assum;
    var_exp = extractpropos(infile,assum);
    //从assum中提取与初始化相关的信息
    for(string s : assum){
    	if(s[0]!='I') continue;
    	if(s.find('=')!=string::npos){
    		int op = s.find('=');
    		string array_name;
    		if(s.find('>')!=string::npos || s.find('<')!=string::npos) op--;
    		op--;
    		array_name = s.substr(1,op-1);
    		if(s.find('(')!=string::npos){//二维数组
    			s = s.substr(s.find('('),s.find(')')-s.find('(')+1);
				int comma = s.find(',');
				array_ass[array_name].emplace_back(stoi(s.substr(1,comma-1)));
				array_ass[array_name].emplace_back(stoi(s.substr(comma+1,s.length()-comma-1)));
    		}else{
    			s = s.substr(s.find('=')+1,s.length()-s.find('=')-1);
    			array_ass[array_name].emplace_back(stoi(s));	
    		}
    	}
    }
   	for(string pro : var_exp){
   		propos_file<<"p"<<++count<<":"<<pro<<endl;
   	}
   	propos_file.close();
}

/*将变量符号化并调用KLEE生成测试用例*/
int KLEE_generate_testcase(){
    src_code_h.open(IP_hpath);
    map<string, string> symbolic_var;//待符号化的变量<变量名，变量类型> 
    while(!src_code_h.eof()){
        string line;
        getline(src_code_h, line);
        if((line.find("int")!=string::npos || line.find("oat")!=string::npos) && line.find(";")!=string::npos){//该行为变量声明代码
            int type_s, type_e;                //定位变量类型的起止位置
            if(line.find("int")!=string::npos){//siint等int型变量
                type_s = line.find("int") - 2; //定位变量类型
                type_e = line.find("int") + 4;
            }else{//float型变量
                type_s = line.find("oat") - 2;
                type_e = line.find("oat") + 4;
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
            //if(var_name.find("[")!=string::npos) var_name = var_name.substr(0,var_name.find("["));
            //if(temp_name.find('*')!=string::npos) temp_name = temp_name.substr(1,temp_name.length()-1);
            var_type[var_name] = vp;
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
    klee_code<<"#include \"klee/klee.h\"\n"<<"#include <string.h>"<<endl;
    while(!src_code_c.eof()){
        string line;
        getline(src_code_c, line);
        klee_code<<line<<endl;
    }
    string filename = get_filename(IP_cpath);
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
        if(const_var.find(it->first)!=const_var.end() && it->first.find('[')==string::npos){//普通浮点数
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
    	}
    	if(it->second.find("float")!=string::npos) continue;
        if(it->second.find("int")!=string::npos && it->first.find('*')!=string::npos){//指针数组符号化
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
            //klee_code<<"for(int i=0; i<17; i++) klee_assume(pRecvbuf[i]!=0);"<<endl;   
        }else if(it->second.find("int")!=string::npos && it->first.find('[')!=string::npos){//整数型数组符号化,通过memcpy传递给结构体中的数组
            	string array_name = it->first.substr(0,it->first.find('['));//使用原数组名加"1"表示临时数组。例如原结构体中数组为ARRAY[10],临时数组为ARRAY1[10]
            	klee_code<<"\t"<<it->second<<" "<<array_name<<"1"<<it->first.substr(it->first.find('['),it->first.length()-it->first.find('['))<<";"<<endl;
            	klee_code<<"\tklee_make_symbolic("<<array_name<<"1,sizeof("<<array_name<<"1"<<"),\""<<it->first<<"\");"<<endl;
            	klee_code<<"\tmemcpy("<<filename<<"1."<<array_name<<","<<array_name<<"1,sizeof("<<array_name<<"1"<<"));"<<endl;
        }else{//普通整型常量符号化
            klee_code<<"\t"<<it->second<<"* "<<"p"<<count<<";\n\t"<<it->second<<" "<<"p"<<count+1<<";\n";
            klee_code<<"\tp"<<count<<"= &"<<filename<<"1."<<it->first<<";\n";
            klee_code<<"\tklee_make_symbolic(&p"<<count+1<<", sizeof(p"<<count+1<<"), \""<<it->first<<"\");\n";
            klee_code<<"\tmemcpy(p"<<count<<", &p"<<count+1<<", sizeof("<<filename<<"1."<<it->first<<"));\n";
            count += 2;
        }       
    }
    klee_code<<"\t"<<filename<<"Fun(&"<<filename<<"1"<<");"<<endl;
    klee_code<<"}"<<endl;
    src_code_c.close();
    src_code_h.close();
    system("clang -I ../klee/include -emit-llvm -c -g klee_code.c");//注意klee/klee.h头文件的存放位置
    system("klee klee_code.bc");
    int num = get_testcasenum(src_path+"klee-last");
    //将所有的测试用例保存
    //if(num>=100) num = 100;
    for(int i=1; i<=num; i++){
    	    string num_i = to_string(i);
    	    stringstream ss;
    	    ss<<setw(6)<<setfill('0')<<num_i;
    	    string num_s;
    	    ss>>num_s;
	    string com = "ktest-tool klee-last/test"+num_s+".ktest > "+src_path+"testcase/testcase_in" + num_i + ".txt";
	    system(com.c_str());
    }
    //remove("klee_code.c");
    remove("klee_code.bc");
    return num; 
}
/*提取测试用例实际值的函数*/
void read_test_case(int index){                               

    test_case.clear();
    int begin_name = 0, end_name = 0;                      	//定位变量名
    int begin_val = 0;                         				//定位变量值起始位置
    string line;                                            //文件中的一行
    string icom = src_path+"/testcase/testcase_in" + to_string(index) + ".txt";
    test_case_infile.open(icom.c_str());
    if (!test_case_infile.is_open())		                           //判断文件是否成功打开
	{
		cout<<"Error opening file:test_case_in.txt"<<endl;
		return;
	}
    string NAME, VAL;                                 //NAME, VAL分别记录变量名，变量值
    while(!test_case_infile.eof()){
        getline(test_case_infile, line);                    //获取文件中单行数据
        begin_name = line.find("name");                     //定位变量名，变量值
        if(begin_name!=string::npos){                     	//输出变量名
            begin_name += 7;                                //从“name”到变量名第一个字符距离为7个字符(固定)
            end_name = line.find("'", begin_name+1);
            NAME = line.substr(begin_name,(end_name-begin_name));
            if(NAME.find("[")!=string::npos){
            	int len = 0;
                if(NAME.find('*')!=string::npos){
                	NAME = NAME.substr(0,NAME.find("["));
                	len = var_type[NAME].size[0];
                }else{//仅一维数组
                	len = stoi(NAME.substr(NAME.find('[')+1,NAME.find(']')-NAME.find('[')-1));
                	//cout<<"len="<<len<<endl;
                } 
                //"hex:"如果测试用例是数组型变量，直接找hex:这行读取数据。该行存放测试用例数组的值
                while(line.find("hex")==string::npos){
            		getline(test_case_infile, line);
				}
				begin_val = line.find("hex") + 8;
			    VAL = line.substr(begin_val, (line.length()-begin_val));
			    //下方只用于一维指针数组处理,KLEE测试用例hex均为小端存储
			    string arr_name;
			    if(NAME.find("*")!=string::npos) arr_name = NAME.substr(1,NAME.length()-1);
			    else arr_name = NAME.substr(0,NAME.find('['));
				for(int i=len-1; i>=0; i--){
					string name = arr_name + '['+to_string(i)+']';
				    string val = to_string(stoul(VAL.substr((len-1-i)*(VAL.length()/var_type[NAME].size[0]), VAL.length()/var_type[NAME].size[0]),nullptr,16));
				    var_last_val[name] = val;
				    test_case[name] = val;
				}
            }else{
            	//测试用例中的普通变量
            	if(var_type[NAME].type.find("unint")!=string::npos){
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
            NAME.clear();
            VAL.clear();
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
    string filename = get_filename(IP_cpath);//文件名与IP名称，内部结构体名称一致
    int size = 0;//只用于结构体中的数组初始化
    string temp[100], array_name;
    vector<string> array;
    for(auto it=test_case.begin(); it!=test_case.end(); it++){
        if(it->first.find('[')!=string::npos){
            array_name = it->first.substr(0, it->first.find('['));//当前数组名
            if(var_type.find("*"+array_name)==var_type.end()) continue;	//该数组在结构体中不是以指针表示
            while(it->first.find(array_name)!=string::npos && it!=test_case.end()){
                int index = extract_index(it->first);
                temp[index] = it->second;
                size++;
                it++; 
            }
            for(auto it=var_type.begin(); it!=var_type.end(); it++){
                if(it->first.find("*"+array_name)!=string::npos){
                    init_code<<it->second.type<<" ";
                    break;
                }
            }
            init_code<<array_name<<"["<<size<<"]={";
            for(int i=0; i<size; i++){
                init_code<<temp[i];
                if(i+1<size) init_code<<",";
            }
            init_code<<"};"<<endl;
            array.push_back(array_name);
            it--;
            size = 0; 
        }
    }
    for(auto it=const_var.begin(); it!=const_var.end(); it++){//打印const_var中所有的浮点数组
    	if(it->first.find('*')!=string::npos)//指针数组在结构体内初始化,但需要将预定义的数组打印
    	init_code<<var_type[it->first.substr(0,it->first.find('['))].type<<" "<<it->first.substr(1,it->first.length()-1)<<"="<<it->second<<endl;
    	else if(it->first.find('[')!=string::npos)
    	init_code<<var_type[it->first].type<<" "<<it->first<<"="<<it->second<<endl;
    }
    init_code<<filename<<" "<<filename<<"1={"<<endl;//利用生成的测试用例初始化结构体中的数据，结构体名称为“文件名1”，例如“Fg333saCheck1”
    init_code<<"\t.fun="<<filename<<"Fun,"<<endl;
    for(auto it=var_type.begin(); it!=var_type.end(); it++){//单独初始化指针变量
        if(it->first.find("*")!=string::npos){
            init_code<<"\t."<<it->first.substr(1,it->first.length()-1)<<"="<<it->first.substr(1,it->first.length()-1)<<","<<endl;
        }
    }
    for(auto it=test_case.begin(); it!=test_case.end(); it++){//初始化生成测试用例的普通变量
     	if(it->first.find("[")!=string::npos && var_type.find("*"+it->first.substr(0,it->first.find("[")))!=var_type.end()) continue;
     	else{
     		init_code<<"\t."<<it->first<<"="<<it->second<<","<<endl;
     	}
     	//else if(var_type[it->first].length()>0) init_code<<"\t."<<it->first<<"="<<it->second<<","<<endl;
    }
    for(auto it=const_var.begin(); it!=const_var.end(); it++){//初始化常数或结构体中的浮点变量
    	if(it->first.find('*')!=string::npos || it->first.find("[")!=string::npos) continue;
    	init_code<<"\t."<<it->first<<"="<<it->second<<","<<endl;
    }
    init_code<<"};\n"<<endl;//结构体初始化完成
    init_code<<"int main(){"<<"\n"<<"\t"<<filename<<"Fun(&"<<filename<<'1'<<");"<<endl;
    //关于const_var中的数组，单独在main函数中处理，直接通过复制的形式传递给结构体中的对应数组
    for(auto it=const_var.begin(); it!=const_var.end(); it++){//初始化结构体中非指针型浮点数组
    	if(it->first.find('*')!=string::npos || it->first.find('[')==string::npos) continue;//指针数组之前已经初始化过了
    	string const_array = it->first.substr(0,it->first.find('['));
    	init_code<<"\tmemcpy("<<filename<<"1."<<const_array<<","<<const_array<<","<<"sizeof("<<const_array<<"));"<<endl;
    }
    init_code<<"\n}"<<endl;//定义main函数，调用IP
    src_code_c.close();
    init_code.close();
}

/*根据提取出的变量值，编写GDB自动化脚本*/
void generate_GDB_script(int index){
    string filename = get_filename(IP_cpath);//提取文件名(无后缀)
    init_code.open(src_path+"gdb_debug_code.c");
    if(!init_code.is_open()){
        cout<<"Error opening file:"<<filename<<endl;
    }
    //remove((src_path+"gdb_script.gdb").c_str());
    if(index==1){
		GDB_script.open(src_path+"gdb_script.gdb",ios::app|ios::out|ios::in);
		int count_line = 0, count_bp = 0;                         //记录程序读入的行数,设置的断点数
		//string t_com = "set logging file GDB_trace/trace" + to_string(index) +".txt";
		GDB_script<<"set logging enabled on"<<endl;
		GDB_script<<"b "<<"gdb_debug_code.c:main"<<endl;
		for(auto it=var_type.begin(); it!=var_type.end(); it++){//在IP初始结构体中出现的变量使用display关键字即可，未在IP中定义，但在命题中出现的需要单独打印
		    if(it->first.find("*")!=string::npos){//指针类型变量，带有指针类型的变量(一般为数组)，可以根据Contract的Assumption初始化
		        string array_name = it->first.substr(1,it->first.length()-1);
		        if(array_ass[array_name].size()==1){//一维数组
		            string len = to_string(array_ass[array_name][0]);
		            for(int i=0; i<stoi(len); i++){
		                if(it->second.type.find("siint")!=string::npos) GDB_script<<"\tdisplay/d "<<array_name<<"["<<i<<"]"<<endl;
		                else if(it->second.type.find("unint")!=string::npos) GDB_script<<"\tdisplay/u "<<array_name<<"["<<i<<"]"<<endl;
		                else if(it->second.type.find("float")!=string::npos) GDB_script<<"\tdisplay/f "<<array_name<<"["<<i<<"]"<<endl;
		            }
		        }   
		    }else if(it->first.find("[")!=string::npos){//数组型变量
		    		string array_name = it->first.substr(0,it->first.find('[')); 
		            if(it->second.size.size()>1){//多维数组:先使用二维数组代替
		            	for(int i=0; i<it->second.size[0]; i++){
		            		for(int j=0; j<it->second.size[1]; j++){
		            			if(it->second.type.find("siint")!=string::npos) GDB_script<<"\tdisplay/d "<<filename<<"1."<<array_name+"["<<i<<"]["<<j<<"]"<<endl;
		                    	else if(it->second.type.find("unint")!=string::npos) GDB_script<<"\tdisplay/u "<<filename<<"1."<<array_name+"["<<i<<"]["<<j<<"]"<<endl;
		                    	else if(it->second.type.find("float")!=string::npos) GDB_script<<"\tdisplay/f "<<filename<<"1."<<array_name+"["<<i<<"]["<<j<<"]"<<endl;
		            		}
		            	}    
		            }else{//一维数组
		                for(int i=0; i<it->second.size[0]; i++){
		                    if(it->second.type.find("siint")!=string::npos) GDB_script<<"\tdisplay/d "<<filename<<"1."<<array_name+"["<<i<<"]"<<endl;
		                    else if(it->second.type.find("unint")!=string::npos) GDB_script<<"\tdisplay/u "<<filename<<"1."<<array_name+"["<<i<<"]"<<endl;
		                    else if(it->second.type.find("float")!=string::npos) GDB_script<<"\tdisplay/f "<<filename<<"1."<<array_name+"["<<i<<"]"<<endl;
		                }
		            }
		    }else{
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
		    if(code.find("src code end")!=string::npos) break;
		    count_line++;
		    if(code.find("if")!=string::npos || code.find("else")!=string::npos || code.find("for")!=string::npos || code.length()<5) continue;//该行为条件判断行,不需要打断点
		    if(code.find('=')==string::npos) continue;		   //该行没有赋值操作           
		    if(code.find("\t.")!= string::npos || code.find(" .")!= string::npos) continue;      //某些结构体变量初始化的过程
		    for(auto it=var_type.begin(); it!=var_type.end(); it++){
		    	string var_name;
		    	if(it->first.find('*')!=string::npos) {
		    		if(find(array.begin(),array.end(),it->first)==array.end()) array.push_back(it->first);
		    		var_name = it->first.substr(1,it->first.length()-1);
		    	}
		    	else if(it->first.find('[')!=string::npos){
		    		if(find(array.begin(),array.end(),it->first.substr(0,it->first.find('[')))==array.end()) array.push_back(it->first.substr(0,it->first.find('[')));
		    		var_name = it->first.substr(0,it->first.find('['));
		    	} 
		    	else var_name = it->first;
		        if(code.find(var_name)!=string::npos){//如果该行代码中存在结构体中定义的变量
		        	//修改：需要定义一个程序keyword，如果搜索到则跳过
		            string temp;
		            count_bp++;
		    		GDB_script<<"b "<<"gdb_debug_code.c"<<":"<<count_line+1<<"\n"<<"\tcommands "<<count_bp<<endl;
		    		if(array.size()>0){
		    			for(string &str : array){
		    				if(str.find('*')!=string::npos) GDB_script<<"\tprintf\"1: I"<<str.substr(1,str.length()-1)<<"I = %d\\n\",sizeof("<<str.substr(1,str.length()-1)<<"),"<<endl;
		    				else GDB_script<<"\tprintf\"1: I"<<str<<"I = %d\\n\", sizeof("<<filename<<"1."<<str<<"),"<<endl;
		    			}
		    		}
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
    }
    src_code_c.close();
    init_code.close();
    //以下用于调用GDB去调试上述生成的初始化后的IP，并生成程序执行日志
    system("gcc -g gdb_debug_code.c -o gdb_debug_code");
    string t_com = "gdb gdb_debug_code -batch -x gdb_script.gdb > GDB_trace/trace" + to_string(index) +".txt";
    system((t_com).c_str());
    remove("gdb_debug_code.c");
    remove("gdb_debug_code");
    //remove("gdb_debug_code");
}



//例如在命题next(countMode)=countMode+1中,计算next(countMode)和countMode+1并比较
bool cal_propos_val(string s){
    //此时表达式中可能依然存在函数，例如min(0.12,0.19),这些需要在z3py中处理，此处考虑的仅为表达式中全部数字的情况
    double val_left, val_right;//计算出的左右表达式的值
    if(s.find("=")!=string::npos){	//left>=/<=/!=/=right
    	int pos_op = s.find("=");
    	if(s[pos_op-1]=='!' || s[pos_op-1]=='>' || s[pos_op-1]=='<'){
    		val_left = Calcu(s.substr(0,pos_op-1));
    		val_right = Calcu(s.substr(pos_op+1, s.length()-pos_op-1));
    		switch(s[pos_op-1]){
    			case '!': 
    				return val_left != val_right;
    			case '>': 
    				return val_left >= val_right;
    			case '<': 
    				return val_left <= val_right;
    			}
    	}else{
    		val_left = Calcu(s.substr(0,pos_op));
    		val_right = Calcu(s.substr(pos_op+1, s.length()-pos_op-1));
    		return val_left == val_right;
    	}
    }else{//只有 > or < 两种可能
    	if(s.find(">")!=string::npos){
    		int pos_op = s.find(">");
    		val_left = Calcu(s.substr(0,pos_op));
    		val_right = Calcu(s.substr(pos_op+1, s.length()-pos_op-1));
    		return val_left > val_right;
    	}else{
    		int pos_op = s.find("<");
    		val_left = Calcu(s.substr(0,pos_op));
    		val_right = Calcu(s.substr(pos_op+1, s.length()-pos_op-1));
    		return val_left < val_right;
    	}
    }
    return true;
}

/*计算将命题中的变量替换为执行路径中的实际输出，用于后续判断命题的正误.*/
void judge_proposition(map<string, pair<string, string>> &next,vector<bool> &propos){
	for(int i=0; i<var_exp.size(); i++){
		string exp = var_exp[i];
		//存在量词的命题，调用z3-slover判断
		if(exp.find("FORALL")!=string::npos || exp.find("EXIST")!=string::npos){
			z3_contract.open(IP_name+".py", ios::app|ios::out|ios::in);
			if (!z3_contract.is_open()) {
				std::cout << "z3_IP_cotract.py file not found!" << std::endl;
				break;
			}
			//Quantifierpropos(string propos, map<string, pair<string, string>>& next, fstream& z3_contract, const string& file_pos);
			propos[i] = Quantifierpropos(exp,next,z3_contract,IP_name+".py");
			continue;
		}
		if(exp.length()==0) continue;
		//特殊函数处理
		if(exp.find("ADDSUM")!=string::npos){
			exp = ADDSUM(exp,var_last_val);
			//propos[i] = cal_propos_val(exp);
		}
		for(auto it=next.begin(); it!=next.end(); it++){
			bool ex_next = false;//命题中是否存在next(it->first)
			while(exp.find("next("+it->first)!=string::npos){//命题中存在next(var)此类表达式
				if(it->second.second.length()!=0) exp.replace(exp.find("next("+it->first),it->first.length()+6,it->second.second);//最新值
				else exp.replace(exp.find("next("+it->first),it->first.length()+6,it->second.first);
				ex_next = true;
			}
			if(ex_next==true){
				while(exp.find(it->first)!=string::npos){
					exp.replace(exp.find(it->first),it->first.length(),it->second.first);//修改为该变量的起始值
				}
			}
		}
		for(auto it=var_last_val.begin(); it!=var_last_val.end(); it++){
		    while(exp.find(it->first)!=string::npos){
		        exp.replace(exp.find(it->first), it->first.length(), it->second);
		        break;
		    }    
		}
		if(exp.length()==0) continue;
		if(exist_alpha(exp)==true) propos[i] = false;//如果字符串中仍然存在字母，说明存在程序执行路径中不存在的变量
		else propos[i] = cal_propos_val(exp);
	}
	return;
}


/*提取执行日志,并转换为etf路径文件*/
void read_trace(int index){

    string line;
    int num_bp = 0;                                   //通过记录执行日志打印的断点数记录生成的路径长度
    bool last_line = false;                           //用于记录是否读到文件末尾，与next操作符关联          
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
    vector<bool> propos(var_exp.size(),0); 
    while(!trace_infile.eof()){         
        getline(trace_infile, line);
        if((line[0]-'0')<10 && (line[0]-'0')>0 && (line.find(':')==string::npos || line.find(':')>4)){      //定位断点的位置，以行开头为数字作为识别标识
            getline(trace_infile, line);
            string para_name, para_val;                         //存储参数名，参数值
            while(line.find(":")!=string::npos && line.find("exited")==string::npos){
                if(line.find('=')==string::npos) break;
                int j = line.find("=");
                if(line.find('.')!=string::npos && line.find(".")<j){//辅助记录变量名的位置，对变量名进行简化，去除掉所在的结构体名或者类(也可以根据需要保留)
                    int aux1;                                   
                    aux1 = line.find('.');
                    para_name = line.substr(aux1+1, j-aux1-2);
                    para_val = line.substr(j+2, line.length()-(j+2));
                }else{//全局变量
                    int aux2 = line.find(':');
                    if(line.find("/f")!=string::npos || line.find("/d")!=string::npos || line.find("/u")!=string::npos) para_name = line.substr(aux2+5, j-aux2-6);
                    else para_name = line.substr(aux2+2, j-aux2-3);
                    para_val = line.substr(j+2, line.length()-(j+2));
                }
                var_last_val[para_name] = para_val;                 //执行日志中最新的变量值存入 
                if(next[para_name].first.empty()){
                    next[para_name].first = para_val;
                }else{
                    next[para_name].second = para_val;
                }
                getline(trace_infile, line);
            }
            if(line.find("exited") != string::npos){
            	judge_proposition(next, propos);
                trace_outfile<<"C "<<num_bp<<" ";
                trace_outfile<<fixed<<setprecision(1)<<1.0*num_bp<<" "<<1.0*(num_bp+1)<<" 0 100.0;";//输出活动的定义 
                for(int j=0; j<propos.size(); j++){
                    trace_outfile<<boolalpha<<"p"<<j+1<<"="<<propos[j];
                    if(j<propos.size()-1) trace_outfile<<",";
                }
                trace_outfile<<"\n";
                num_bp++;
            	break;
            }else{
            	judge_proposition(next, propos);
		        trace_outfile<<"C "<<num_bp<<" ";
		        trace_outfile<<fixed<<setprecision(1)<<1.0*num_bp<<" "<<1.0*(num_bp+1)<<" 0 100.0;";//输出活动的定义  
		        for(int j=0; j<propos.size(); j++){
		            trace_outfile<<boolalpha<<"p"<<j+1<<"="<<propos[j];
		            if(j<propos.size()-1) trace_outfile<<",";
		        }
		        trace_outfile<<"\n";
		        num_bp++;
		        for(auto it=next.begin(); it!=next.end(); it++){
		            if(it->second.second.length() != 0) it->second.first = it->second.second;
		        }
            }  
        }                                   
    }
    trace_outfile<<"S 0; name = s1\n"<<"F 0 0 "<<1.0*num_bp<<" 1.0 0.0 0.0"<<endl;
    trace_infile.close();
    trace_outfile.close();
    return;
}


int main(){
    
    /*
	const_var["royaw"] = "0.465";
	const_var["piyaw"] = "0.214";
	const_var["*pGyroRate[3]"] = "{-0.215, -0.123, 0.006};"; 
	*/
	/*
	const_var["royaw"] = "1.206";
	const_var["piyaw"] = "1.689";
	const_var["*pGyroRate[3]"] = "{-0.076, -0.079, 0.102};";
	*/
	clock_t start_time, end_time;
    extract_var();
    start_time=clock();
    int count = KLEE_generate_testcase();
    for(int i=1; i<=count; i++){
		read_test_case(i);
		generate_execu_log();
		generate_GDB_script(i);
		init_code.close();
		read_trace(i);
		var_last_val.clear();		                       
    }
    remove("gdb_script.gdb");
    end_time=clock();
    cout << "The run time is: " <<(double)(end_time - start_time)/CLOCKS_PER_SEC<< "s" << endl;
    return 0;
}
