//���ļ���¼main.cpp�е��õĸ����������书���������Զ������̲�ֱ�����
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
    tree::ParseTree* tree = parser.prog(); 	//parser.grog����prog�����﷨�ļ�����ʼ��������
    EvalVisitor eval; 						//ʵ�����Զ���ķ�������
    eval.visit(tree); 						//ͨ��visit()������ʼ�����﷨��
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

//����������next(countMode)=countMode+1��,����next(countMode)��countMode+1���Ƚ�
bool cal_propos_val(string &s){
    //��ʱ���ʽ�п�����Ȼ���ں���������min(0.12,0.19),��Щ��Ҫ��z3py�д����˴����ǵĽ�Ϊ���ʽ��ȫ�����ֵ����
    double val_left, val_right;//����������ұ��ʽ��ֵ
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
    }else{//ֻ�� > or < ���ֿ���
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
					  fstream& z3_constraint)//next������������еı����ľ���ֵ
{
	z3_contract.seekp(0, ios::end);//д��λ���ƶ���contractĩβ
	streampos pos = z3_contract.tellg();//��ȡ�ļ���С
    z3_contract << "\n" << endl;
    propos_file.open(propos_file_path, ios::app | ios::in | ios::out);
    if (!propos_file.is_open())		               	//�ж��ļ��Ƿ�ɹ���
	{
		cout<<"Error opening file: IP_propos.txt"<<endl;
		return false;
	}
	//�Ѿ���ӽ�z3��Լ�������ظ����
	vector<string> cache;
    while(!propos_file.eof()){
    	string line;
    	getline(propos_file,line);
    	for(auto it=next.begin(); it!=next.end(); it++){
     		string propos = line;
    		string index = it->first.find('[')!=string::npos?it->first.substr(0,it->first.find('[')+1):it->first;
    		string array_name = it->first.find('[')!=string::npos?it->first.substr(0,it->first.find('[')):"";
    		//if(find(cache.begin(),cache.end(),"next("+index)!=cache.end() || find(cache.begin(),cache.end(),index)!=cache.end()) continue;
    		//�������е������inf��z3�޷�����
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
				//������Ҫ���⴦��,����ȡ������
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
				/*��z3�н�list����ת��Ϊarray���ͣ�ת��������python�ļ��ж���
				���ñ���var�������д���next(var)ʱ��ԭ������var���ʽ��ָ����ʼ������Ϣ*/
				if(it->first.find('[')!=string::npos){
					z3_contract << "VER_"+array_name+"_next, constraints" << " = List2Array(" << array_name+"_next" << ",idx=())"<< endl;
					z3_contract << array_name << "=" << it->second.first << endl;
					if(find(cache.begin(),cache.end(),index)==cache.end())
						z3_contract << "VER_"+array_name+", constraints" << " = List2Array(" << array_name+",idx=())"<< endl;
				}
				else if(find(cache.begin(),cache.end(),index)==cache.end())
					z3_contract << "s.add(" << it->first << "==" << it->second.first << ")" << endl;
				cache.emplace_back(index);
			}else if(propos.find(index)!=string::npos && find(cache.begin(),cache.end(),index)==cache.end()){//��ӡ����ֵ
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
    
    //����ʹ��z3�ı�д��contractԼ����������constraint�ļ���
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
	unsigned char ch[4];//�洢16���Ʊ�ʾ��IEEE754��׼32λ������
	for (size_t i = 0; i < VAL.length(); i+=2){
		string byteString = VAL.substr(i, 2);
		unsigned char byte = (unsigned char)strtol(byteString.c_str(), nullptr, 16);
		ch[(i%8)/2] = byte;
		if((i%8)/2==3){
			string float_val = to_string(Hex32_10(ch));
			if(float_val.find('n')!=string::npos || float_val.find('N')!=string::npos) float_val = "0.0";//����NaN����ֹ���������ֵ�޸�Ϊ0
			test_case[NAME] += float_val;
			if(i+2<VAL.length()) test_case[NAME] += ',';
		}
	}
	return;
}

double Hex64_10(unsigned char *Byte) {
	
    //char* pData = byteDate.data();
    //����λ  1λ
    int sign = int(Byte[0] >> 7);
    //ָ��λ  11λ
    int e = int(((Byte[0] & 0x7F) << 4) & 0x0FF0 | (Byte[1] & 0xF0) >> 4) - 1023;
    //С��λ  52λ
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
	unsigned char ch[8];//�洢16���Ʊ�ʾ��IEEE754��׼64λ������
	for (size_t i = 0; i < VAL.length(); i+=2){
		string byteString = VAL.substr(i, 2);
		unsigned char byte = (unsigned char)strtol(byteString.c_str(), nullptr, 16);
		ch[7-(i%16)/2] = byte;
		if((7-(i%16)/2)==0){
			string double_val = to_string(Hex64_10(ch));
			if(double_val.find('n')!=string::npos || double_val.find('N')!=string::npos) double_val = "0.0";//����NaN����ֹ���������ֵ�޸�Ϊ0
			test_case[NAME] += double_val;
			if(i+2<VAL.length()) test_case[NAME] += ',';
		}
	}
	return;
}
