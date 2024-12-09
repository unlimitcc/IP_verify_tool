#ifndef _AUX_FUN_H_
#define _AUX_FUN_H_
#include "Database.h"
#include <string>
#include <map>
#include <fstream>
#include <regex>
#include <dirent.h>
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

/*�ж��ַ������Ƿ����next����������ڼ�����true*/
bool containsNext(const std::string& s);

/*�ж�ĳ�ļ��Ƿ���ڣ����ڼ�����true*/
bool isFileExists_ifstream(string &name);

/*��ȡ���ɵĲ�����������*/
int get_testcasenum(const string &path); 

/*�ж�һ���ַ������Ƿ������ĸ*/
bool exist_alpha(const string str);

/*�ַ���ֵ������*/
double Calcu(string expr);

/*contract�ļ��﷨��������ȡ����*/
vector<string> extractpropos(string infile, vector<string>& assum);

/*����������next(countMode)=countMode+1��,����next(countMode)��countMode+1���Ƚ�*/
bool cal_propos_val(string &s);

/*�жϺ�������Լ�����������ȷ��*/
void Z3_Prover_Propos(fstream& propos_file, 
					  const string& propos_file_path,
				 	  map<string, pair<string, string>>& next,
					  fstream& z3_contract, 
					  const string file_pos,
					  fstream& z3_constraint,
					  const bool &first_time,
					  vector<string> &z3_propos,
					  vector<bool> &propos);

/*�����ȸ�����Ԥ����*/
void extract_float(const string& VAL, map<string,string>& test_case, const string & NAME);

/*32λʮ�����Ƶ�������*/
float Hex32_10(unsigned char *Byte);

/*˫���ȸ�����Ԥ����*/
void extract_double(const string& VAL, map<string,string>& test_case, const string & NAME);

/*64λʮ�����Ƶ�������*/
double Hex64_10(unsigned char *Byte);
#endif
