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

/*判断某文件是否存在，存在即返回true*/
bool isFileExists_ifstream(string &name);

/*处理累加操作，目前只用于sacheck中属性的检查*/
string ADDSUM(string s, std::map<string, string> mp);

/*从文件路径中提取文件名(无扩展名)*/ 
string get_filename(string path);

/*从数组字符串中提取出下标，例字符串pbuff[14]中提取14*/ 
int extract_index(string s);

/*从一个表达式中提取数字:|pbuff|>17中提取17*/
int extract_len(string s);

/*从条件分支语句中提取出涉及到的变量，包括变量名和变量类型
string s表示读入的条件分支语句，vector<string> var表示从待验证属性中提取出的变量*/ 
void find_symbolic_var(string s, map<string, string>var_type, map<string, string> &symbolic_var, map<string, unint32> &array);

/*读取生成的测试用例数量*/
int get_testcasenum(const string &path); 

/*判断一个字符串中是否存在字母*/
bool exist_alpha(const string str);

/*字符串值计算器*/
double Calcu(string expr);

/*contract文件语法分析并提取命题*/
vector<string> extractpropos(string infile, vector<string>& assum);

/*判断含有量词约束的命题的正确性*/
bool Quantifierpropos(string propos, map<string, pair<string, string>>& next, fstream& z3_contract, const string file_pos);
#endif
