//该文件记录main.cpp中调用的辅助函数，其功能与整个自动化过程不直接相关
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "aux_fun.h"


using namespace std;
using namespace antlr4;

bool containsNext(const std::string& s) {
    return s.find("next") != std::string::npos;
}


bool isFileExists_ifstream(std::string& name) {
    
    std::ifstream f(name.c_str());
    return f.good();
}


int get_testcasenum(const string &path){  
    int testcase_num=0;
    DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(path.c_str())))
        return testcase_num;
    while((ptr=readdir(pDir))!=0){
        if(strcmp(ptr->d_name,".")!=0 && strcmp(ptr->d_name,"..")!=0){
           string filename = ptr->d_name;
           if(filename.find("test00")!=string::npos && filename.find(".ktest")!=string::npos) testcase_num++;
        }           
    }
    closedir(pDir);
    return testcase_num;
}

bool exist_alpha(const string str){
	for(char c : str){
		if(isalpha(c)){
			return true;
		}
	}
	return false;
}

double Calcu(string expr){
	expr = expr + "\n";
    ANTLRInputStream input(expr);
    NCLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    NCParser parser(&tokens);
    tree::ParseTree* tree = parser.prog(); 	//parser.grog其中prog就是语法文件的起始规则名称
    EvalVisitor eval; 						//实例化自定义的访问器类
    eval.visit(tree); 						//通过visit()函数开始遍历语法树
    return eval.res;
}


class demoListener: public contractBaseListener{
public:
	vector<string> propos;
	vector<string> ass;	
public:
	void enterPropos(contractParser::ProposContext* ctx){
		if(find(propos.begin(),propos.end(),ctx->getText())==propos.end()){
			propos.emplace_back(ctx->getText());
		}
	}
	void enterCond(contractParser::CondContext* ctx){
		propos.emplace_back(ctx->getText());
		ass.emplace_back(ctx->getText());
	}
};

vector<string> extractpropos(string input_file, vector<string>& assum){
	ifstream property_file;
	property_file.open(input_file,ios::app | ios::out | ios::in);
    ANTLRInputStream input(property_file);
    contractLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
   	contractParser parser(&tokens);
   	tree::ParseTree* tree = parser.file();
   	demoListener demo;
   	tree::ParseTreeWalker::DEFAULT.walk(&demo, tree);
   	property_file.close();
   	assum = demo.ass;
    return demo.propos;
}

//例如在命题next(countMode)=countMode+1中,计算next(countMode)和countMode+1并比较
bool cal_propos_val(string &s){
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

bool Z3_Prover_Propos(fstream& propos_file, 
					  const string& propos_file_path,
				 	  map<string, pair<string, string>>& next,
					  fstream& z3_contract, 
					  const string file_pos,
					  fstream& z3_constraint)//next数组里包含所有的变量的具体值
{
	z3_contract.seekp(0, ios::end);//写入位置移动到contract末尾
	streampos pos = z3_contract.tellg();//读取文件大小
    z3_contract << "\n" << endl;
    propos_file.open(propos_file_path, ios::app | ios::in | ios::out);
    if (!propos_file.is_open())		               	//判断文件是否成功打开
	{
		cout<<"Error opening file: IP_propos.txt"<<endl;
		return false;
	}
	//已经添加进z3的约束不用重复添加
	vector<string> cache;
    while(!propos_file.eof()){
    	string line;
    	getline(propos_file,line);
    	for(auto it=next.begin(); it!=next.end(); it++){
     		string propos = line;
    		string index = it->first.find('[')!=string::npos?it->first.substr(0,it->first.find('[')+1):it->first;
    		string array_name = it->first.find('[')!=string::npos?it->first.substr(0,it->first.find('[')):"";
    		//if(find(cache.begin(),cache.end(),"next("+index)!=cache.end() || find(cache.begin(),cache.end(),index)!=cache.end()) continue;
    		//浮点数中的无穷大inf，z3无法解析
    		while(it->second.first.find("inf")!=string::npos){
    			int st = it->second.first.find("inf");
    			it->second.first.replace(st,3,"3.4e+38");
    		}
    		while(it->second.second.find("inf")!=string::npos){
    			int st = it->second.second.find("inf");
    			it->second.second.replace(st,3,"3.4e+38");
    		}
			if(propos.find("next("+index)!=string::npos && find(cache.begin(),cache.end(),"next("+index)==cache.end()){
				cache.emplace_back("next("+index);
				//数组需要特殊处理,先提取数组名
				if(it->second.second.length()!=0){
					if(it->first.find('[')!=string::npos) \
						z3_contract << array_name << "_next" << "=" << it->second.second << endl;
					else \
						z3_contract << "s.add(" << it->first << "_next==" << it->second.second << ")" << endl;
				}else{
					if(it->first.find('[')!=string::npos) \
						z3_contract << array_name << "_next" << "=" << it->second.first << endl;
					else \
						z3_contract << "s.add(" << it->first << "_next==" << it->second.first << ")" << endl;
				}
				/*在z3中将list类型转化为array类型，转换函数在python文件中定义
				当该变量var在命题中存在next(var)时，原命题中var表达式均指代初始变量信息*/
				if(it->first.find('[')!=string::npos){
					z3_contract << "VER_"+array_name+"_next, constraints" << " = List2Array(" << array_name+"_next" << ",idx=())"<< endl;
					z3_contract << array_name << "=" << it->second.first << endl;
					if(find(cache.begin(),cache.end(),index)==cache.end())
						z3_contract << "VER_"+array_name+", constraints" << " = List2Array(" << array_name+",idx=())"<< endl;
				}
				else if(find(cache.begin(),cache.end(),index)==cache.end())
					z3_contract << "s.add(" << it->first << "==" << it->second.first << ")" << endl;
				cache.emplace_back(index);
			}else if(propos.find(index)!=string::npos && find(cache.begin(),cache.end(),index)==cache.end()){//打印最新值
				cache.emplace_back(index);
				/*if(it->second.second.length()==0){
					if(it->first.find('[')!=string::npos) \
						z3_contract << array_name << "=" << it->second.first << endl;
					else \
						z3_contract << "s.add(" << it->first << "==" << it->second.first << ")" << endl;
				}else{	
				}*/
				if(it->first.find('[')!=string::npos) \
						z3_contract << array_name << "=" << it->second.first << endl;
					else \
						z3_contract << "s.add(" << it->first << "==" << it->second.first<< ")" << endl;
				if(it->first.find('[')!=string::npos)
					z3_contract << "VER_"+array_name << ", constraints = List2Array(" << array_name << ", idx=())" << endl;
			}
		}
    }
    
    //输入使用z3的编写的contract约束，保存在constraint文件里
    z3_constraint.open("z3_constraint.py",ios::app | ios::out | ios::in);
    while(!z3_constraint.eof()){
    	string line;
    	getline(z3_constraint,line);
    	z3_contract << line << endl;
    }
    z3_constraint.close();
    z3_contract << "print(s.check())" << endl;
    char buffer[100];
    string res;
	FILE* fp;
	string com = "python3 " + file_pos;
	fp = popen(com.c_str(), "r");
	if(fp == NULL){
		cout << "z3-solver failed\n" << endl;
		exit(1);
	}else{
        if(fread(buffer,1,sizeof(buffer)-1,fp) > 0) {
            res = buffer;
        }
	}
	pclose(fp);
	z3_contract.seekp(0, ios::beg);
   	truncate(file_pos.c_str(),pos);
    z3_contract.close();
    propos_file.close();
    if(res.find("unsat")!=string::npos) return false;
    else if(res.find("sat")!=string::npos) return true;
    else return false;
}

float Hex32_10(unsigned char *Byte){
    
    return *((float*)Byte);
}

void extract_float(const string& VAL, map<string,string>& test_case, const string & NAME){
	unsigned char ch[4];//存储16进制表示的IEEE754标准32位浮点数
	for (size_t i = 0; i < VAL.length(); i+=2){
		string byteString = VAL.substr(i, 2);
		unsigned char byte = (unsigned char)strtol(byteString.c_str(), nullptr, 16);
		ch[(i%8)/2] = byte;
		if((i%8)/2==3){
			string float_val = to_string(Hex32_10(ch));
			if(float_val.find('n')!=string::npos || float_val.find('N')!=string::npos) float_val = "0.0";//出现NaN，防止程序崩溃将值修改为0
			test_case[NAME] += float_val;
			if(i+2<VAL.length()) test_case[NAME] += ',';
		}
	}
	return;
}

double Hex64_10(unsigned char *Byte) {
	
    //char* pData = byteDate.data();
    //符号位  1位
    int sign = int(Byte[0] >> 7);
    //指数位  11位
    int e = int(((Byte[0] & 0x7F) << 4) & 0x0FF0 | (Byte[1] & 0xF0) >> 4) - 1023;
    //小数位  52位
    double  m = pow(2, -52) * 
        (pow(256, 6) * double(Byte[1] & 0x0F) +
         pow(256, 5) * double(Byte[2]) +
         pow(256, 4) * double(Byte[3]) +
         pow(256, 3) * double(Byte[4]) +
         pow(256, 2) * double(Byte[5]) +
         256 * double(Byte[6]) +
         double(Byte[7])) + 1;
    double res = pow(-1, sign) * m * pow(2, e);
    return res;
}

void extract_double(const string& VAL, map<string,string>& test_case, const string & NAME){
	unsigned char ch[8];//存储16进制表示的IEEE754标准64位浮点数
	for (size_t i = 0; i < VAL.length(); i+=2){
		string byteString = VAL.substr(i, 2);
		unsigned char byte = (unsigned char)strtol(byteString.c_str(), nullptr, 16);
		ch[7-(i%16)/2] = byte;
		if((7-(i%16)/2)==0){
			string double_val = to_string(Hex64_10(ch));
			if(double_val.find('n')!=string::npos || double_val.find('N')!=string::npos) double_val = "0.0";//出现NaN，防止程序崩溃将值修改为0
			test_case[NAME] += double_val;
			if(i+2<VAL.length()) test_case[NAME] += ',';
		}
	}
	return;
}
