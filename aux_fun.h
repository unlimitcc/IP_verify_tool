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

/*判断字符串中是否存在next运算符，存在即返回true*/
bool containsNext(const std::string& s);

/*判断某文件是否存在，存在即返回true*/
bool isFileExists_ifstream(string &name);

/*读取生成的测试用例数量*/
int get_testcasenum(const string &path); 

/*判断一个字符串中是否存在字母*/
bool exist_alpha(const string str);

/*字符串值计算器*/
double Calcu(string expr);

/*contract文件语法分析并提取命题*/
vector<string> extractpropos(string infile, vector<string>& assum);

/*例如在命题next(countMode)=countMode+1中,计算next(countMode)和countMode+1并比较*/
bool cal_propos_val(string &s);

/*判断含有量词约束的命题的正确性*/
void Z3_Prover_Propos(fstream& propos_file, 
					  const string& propos_file_path,
				 	  map<string, pair<string, string>>& next,
					  fstream& z3_contract, 
					  const string file_pos,
					  fstream& z3_constraint,
					  const bool &first_time,
					  vector<string> &z3_propos,
					  vector<bool> &propos);

/*单精度浮点数预处理*/
void extract_float(const string& VAL, map<string,string>& test_case, const string & NAME);

/*32位十六进制到浮点数*/
float Hex32_10(unsigned char *Byte);

/*双精度浮点数预处理*/
void extract_double(const string& VAL, map<string,string>& test_case, const string & NAME);

/*64位十六进制到浮点数*/
double Hex64_10(unsigned char *Byte);
#endif
