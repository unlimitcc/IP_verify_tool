/* 该程序用于调用tracp4cps工具验证生成的TRACE模型*/
#include "call_trace4cps.h"

call_trace4cps::call_trace4cps(const string &jar_path, const string &spec, const string &TRACE){

	java_API = jar_path;//"trace4cps/temporallogic/org.eclipse.trace4cps.tl.cmd/target/eclipse-trace4cps-incubation-dev/lib/org.eclipse.trace4cps.tl.cmd-0.2.0-SNAPSHOT.jar";
	path_spec = spec;	//"property.etl";
	path_trace = TRACE;	//"TRACE/TRACE";

}


void call_trace4cps::verify(const int index, const bool Z3_API){

	string com = "java -jar " + java_API + " " + path_spec + " " + path_trace + to_string(index) + ".etf";//+ " > IP_verify_result/TRACE" + to_string(index) + "_result.txt";
	const char* cmd = com.c_str();
	// 使用 popen 来执行命令并读取输出
	vector<char> buffer(256);
	unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	if (!pipe) {
	    throw runtime_error("popen() failed!");
	}
	string result;
	//旧IP待验证性质未取反，TRACE判断逻辑与其他部分相反
	if(Z3_API){
		while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
			result = buffer.data();
			if(result.find("#UNSAT = 0")!=string::npos){
				flag = true;
				break;
			} 
			else if(result.find(": BAD")!=string::npos || result.find("#UNSAT = ")!=string::npos){
				cout << "Please check trace" << index <<endl;
				flag = false;
				break; 
			} 
		}
	}else{
		// 读取命令的输出到 result 字符串中
		while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		    result = buffer.data();
		    //cout << "result = " << result << endl;
		    if(result.find("#UNSAT = 0")!=string::npos){
		    	cout << "Please check trace" << index <<endl;
				flag = false; //找到了反例路径
				break;
			}
			if(result.find(": BAD")!=string::npos || result.find("#UNSAT = ")!=string::npos){
				flag = true; //不满足，即该路径不满足not P，即为成立
				break; 
			} else {
				throw std::runtime_error("TRACE工具待验证性质输入错误, 当前输出结果:" + result);
		 	} 
		}
	}
	return;
}


