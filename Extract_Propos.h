#pragma once
#include "Header_File.h"
#include <regex>
using namespace std;

class extract_propos{

private:
		
	struct keycompare {
    	bool operator()(const string&a, const string&b) const {
        	//按string的长度排列
        	if (a.length() != b.length()) {
            	return a.length() > b.length();
        	}
        	return a < b; // 保持字典序升序以保证唯一性
		}
	};
	
	ifstream property_infile;                                      //待验证性质文件，以规定的形式编写
	fstream propos_file;										   //存放从contract中提取中的所有命题
	fstream TRACE_property_file;								   //转化生成的TRACE性质文件
	map<string, string, keycompare> trace_propos;							   //存放TRACE性质文件中p命题和真实命题的对应关系,例如 pair <p1,m_workMode = 0>
	bool Z3_API;
	
public:
	
	/*z3的命题集合, [0]=Assumption, [1]=Guarantees/Guarantee1 ...*/
	vector<string> z3_propos;                             
	/*构造函数: 标识是否调用z3，如果调用z3，则无需提取各个单位子命题，将propos中的完整的独立子命题提取即可
	 *假设关键字 : Assumptions,
	 *保证关键字 : Guarantee1(最后一位为编码)，或者只有一个综合保证时，使用Guarantees。
	 *总之，使用Guarantee作为搜索关键字即可。
	 *不调用z3，则分别提取各个单位自命题。
	 *最终，所有命题编码为TRACE模型中的对应命题p1~pn。
	 */
	
	/*存在next操作符的变量集合*/
	map<string,bool> ex_next;
	
	extract_propos(bool use_z3);
	
	void get_propos(const string &src_path, 
					const string &IP_name,
					unordered_map<string,vector<int>> &array_ass, 
					vector<string> &var_exp);
	void get_propos_next(const map<string, pair<string, string> > &next, const vector<string> &var_exp);
	//将.ltl文本格式的性质转化为TRACE格式
	void trans_TRACE_property(const string &src_path, const string &IP_name);

};
