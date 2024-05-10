//���ļ���¼main.cpp�е��õĸ����������书��ȥ�����Զ������̲�ֱ�����
#include <iostream>
#include <fstream>
#include <string>
#include "aux_fun.h"

using namespace std;
using namespace antlr4;

bool isFileExists_ifstream(std::string& name) {
    
    std::ifstream f(name.c_str());
    return f.good();
}

string ADDSUM(string s, map<string, string>mp){
    int p = 1, end;//p��ջָ�룬������ȡ����ADDSUM���ʽ
    end = s.find("ADDSUM");
    while(p>0){
        if(s[end]=='('){
            p++;
        }else if(s[end]==')'){
            p--;
        }
        end++;
    }                                                        
    string s_add = s.substr(s.find("ADDSUM"), end-s.find("ADDSUM")-1);              //ȷ�������ۼ�ʽ�ķ�Χ
    int begin = 1;
    while(s_add[begin]!=')') begin++;               //��ȡ�ۼ�ʽ�Ĵ�������ʽ����
    string s_add_cal = s_add.substr(begin+2, s_add.length()-begin-3);
    int range = s_add.find('~');
    int st = range, ed = range;
    while(s_add[st]!=':') st--;
    while(s_add[ed]!=')') ed++;
    siint32 top = atoi(s_add.substr(st+1, range-st-1).c_str());
    siint32 down = atoi(s_add.substr(range+1, ed-range).c_str());
    int be = st;
    while(s_add[be]!='(') be--;
    string var_name = s_add.substr(be+1,st-be-1);
    string s_trans;                                         //��¼ת������ַ���
    string temp;                                            //��¼���ۼ�ʽת������ַ���
    smatch results;
    string pattern(var_name);//����ƥ��������������ģ��
    regex r(pattern);
    string::const_iterator itb = s_add_cal.begin();//��������������ڷ��������ַ���
    string::const_iterator ite = s_add_cal.end();
    for(int i=top; i<=down; i++){
        string temp_s_add_cal = s_add_cal;
        while(s_add_cal.find(var_name)!=string::npos && regex_search(itb, ite, results, r)){
            s_add_cal.replace(s_add_cal.find(var_name), var_name.length(), to_string(i));
        }
        temp += s_add_cal;
        if(i<down) temp += '+';
        s_add_cal = temp_s_add_cal;
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        while(temp.find(it->first)!=string::npos){
            temp.replace(temp.find(it->first), it->first.length(), it->second);
        }
    }
    s_trans = s.replace(s.find("ADDSUM"), s_add.length(), temp);
    return s_trans;
}

string get_filename(string path){//path��ʾ�ļ����ڵľ���·��
    int st_name = path.find_last_of("/")+1; //��ʶ�ļ�������ʼλ��
    int ed_name = path.find_last_of('.'); //��ʶ�ļ�����ĩβλ��
    string filename = path.substr(st_name, ed_name-st_name);
    return filename;
}

int extract_index(string s){
    int r = s.find(']');
    int l = s.find('[');
    string index = s.substr(l+1, r-l-1);
    return atoi(index.c_str());
}

int extract_len(string s){
    int len;
    smatch results;
    string pattern("[0-9]+");//��������
    regex r(pattern);
    string::const_iterator itb = s.begin();//��������������ڷ��������ַ���
    string::const_iterator ite = s.end();
    string temp;
    while(regex_search(itb, ite, results, r)){
        temp = results[0];
        len = stoi(temp);
        break;
    }
    return len;
}

void find_symbolic_var(string s, map<string, string>var_type, map<string, string> &symbolic_var, map<string, unint32> &array){
    smatch results;
    string pattern1("[A-Za-z0-9_]+");//����ƥ��������������ģ��
    string pattern2("[A-Za-z0-9]+\\[[0-9]+\\]");//����ƥ�������������ģ��
    regex r1(pattern1);
    regex r2(pattern2);
    string::const_iterator itb = s.begin();//��������������ڷ��������ַ���
    string::const_iterator ite = s.end();
    string temp;
    while(regex_search(itb, ite, results, r2)){
        temp = results[0];
        string name = temp.substr(0, temp.find('['));
        if(array[name]<extract_index(temp)) array[name] = extract_index(temp);
        itb = results[0].second;
    }
    itb = s.begin();
    while(regex_search(itb, ite, results, r1)){
        temp = results[0];
        for(auto it=var_type.begin(); it!=var_type.end(); it++){
            if(it->first==temp){
                symbolic_var[temp] = var_type[temp];
                break;
            }
        }
        itb = results[0].second;
    }
    return;
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

bool Quantifierpropos(string propos, map<string, pair<string, string>>& next, fstream& z3_contract, const string file_pos){
	z3_contract.seekp(0, ios::end);//д��λ���ƶ���contractĩβ
	streampos pos = z3_contract.tellg();//��ȡ�ļ���С
    z3_contract << "\n" << endl;
    for(auto it=next.begin(); it!=next.end(); it++){
    	if(propos.find("next("+it->first)!=string::npos){
    		//������Ҫ���⴦��
			while(propos.find("next("+it->first)!=string::npos){
				int st = propos.find("next("+it->first);
				string array_name, array_index;
				if(it->first.find('[')!=string::npos){
					array_name = it->first.substr(0,it->first.find('['));
					array_index = it->first.substr(it->first.find('['),it->first.length()-it->first.find('['));
				}
				if(it->second.second.length()==0){
					if(it->first.find('[')!=string::npos){
						z3_contract << "s.add(" << array_name << "_next" << array_index << "==" << it->second.first << ")" << endl;
					}else z3_contract << "s.add(" << it->first << "_next==" << it->second.first << ")" << endl;
					propos.replace(st,st+it->first.length()+6,"");
				}else{
					if(it->first.find('[')!=string::npos){
						z3_contract << "s.add(" << array_name << "_next" << array_index << "==" << it->second.second << ")" << endl;
					}else z3_contract << "s.add(" << it->first << "_next==" << it->second.second << ")" << endl;
					propos.replace(st,st+it->first.length()+6,"");
				}
			}
			while(propos.find(it->first)!=string::npos){
				int st = propos.find(it->first);
				z3_contract << "s.add(" << it->first << "==" << it->second.first << ")" << endl;
				propos.replace(st,st+it->first.length(),"");
			}
    	}else{
    		while(propos.find(it->first)!=string::npos){
				int st = propos.find(it->first);
				if(it->second.second.length()==0){
					z3_contract << "s.add(" << it->first << "==" << it->second.first << ")" << endl;
					propos.replace(st,st+it->first.length(),"");
				}else{
					z3_contract << "s.add(" << it->first << "==" << it->second.second << ")" << endl;
					propos.replace(st,st+it->first.length(),"");
				}
			}
    	}
    }
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
    if(res=="unsat") return false;
    else return true;
}


