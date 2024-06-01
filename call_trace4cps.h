#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class call_trace4cps{

private:
	//待验证性质文件路径
	string path_spec;
	//待验证路径模型文件路径
	string path_trace;
	
	//TRACE4CPS工具接口路径
	string java_API;
public:
	
	//trace是否满足contract
	bool flag;
	
	call_trace4cps(const string &jar_path, const string &spec, const string &TRACE);
	//通过命令行方式实现调用trace工具,验证结果存放在result文件中
	void verify(const int index);
	
};

