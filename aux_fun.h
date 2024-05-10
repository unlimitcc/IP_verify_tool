#ifndef _AUX_FUN_H_
#define _AUX_FUN_H_
#include "Database.h"
#include <string>
#include <map>
#include <regex>
#include <dirent.h>
#include "/usr/include/python3.10/Python.h"
#include "antlr4-runtime.h"
#include "antlr4_cal/NCLexer.h"
#include "antlr4_cal/NCParser.h"
#include "antlr4_cal/EvalVisitor.h"
#include "antlr4_propos/contractLexer.h"
#include "antlr4_propos/contractParser.h"
#include "antlr4_propos/contractBaseListener.h"
#include <cctype>
using namespace std;
#include <unistd.h>

/*�ж�ĳ�ļ��Ƿ���ڣ����ڼ�����true*/
bool isFileExists_ifstream(string &name);

/*�����ۼӲ�����Ŀǰֻ����sacheck�����Եļ��*/
string ADDSUM(string s, std::map<string, string> mp);

/*���ļ�·������ȡ�ļ���(����չ��)*/ 
string get_filename(string path);

/*�������ַ�������ȡ���±꣬���ַ���pbuff[14]����ȡ14*/ 
int extract_index(string s);

/*��һ�����ʽ����ȡ����:|pbuff|>17����ȡ17*/
int extract_len(string s);

/*��������֧�������ȡ���漰���ı����������������ͱ�������
string s��ʾ�����������֧��䣬vector<string> var��ʾ�Ӵ���֤��������ȡ���ı���*/ 
void find_symbolic_var(string s, map<string, string>var_type, map<string, string> &symbolic_var, map<string, unint32> &array);

/*��ȡ���ɵĲ�����������*/
int get_testcasenum(const string &path); 

/*�ж�һ���ַ������Ƿ������ĸ*/
bool exist_alpha(const string str);

/*�ַ���ֵ������*/
double Calcu(string expr);

/*contract�ļ��﷨��������ȡ����*/
vector<string> extractpropos(string infile, vector<string>& assum);

/*�жϺ�������Լ�����������ȷ��*/
bool Quantifierpropos(string propos, map<string, pair<string, string>>& next, fstream& z3_contract, const string file_pos);
#endif
