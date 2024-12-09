#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

class call_trace4cps{

private:
	//待验证性质文件路径
	string path_spec;
	//待验证路径模型文件路径
	string path_trace;
	//TRACE4CPS工具接口路径
	string java_API;
	//同时验证多条性质时，统计每条性质的验证结果，用于定位错误的性质
	//map<string, bool> 
public:
	
	//trace是否满足contract
	bool flag;
	
	call_trace4cps(const string &jar_path, const string &spec, const string &TRACE);
	//通过命令行方式实现调用trace工具,验证结果存放在result文件中
	void verify(const int index, const bool Z3_API);
	
};

