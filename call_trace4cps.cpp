/* 该程序用于调用tracp4cps工具验证生成的TRACE模型*/
#include "call_trace4cps.h"

call_trace4cps::call_trace4cps(const string &jar_path, const string &spec, const string &TRACE){

	java_API = jar_path;//"trace4cps/temporallogic/org.eclipse.trace4cps.tl.cmd/target/eclipse-trace4cps-incubation-dev/lib/org.eclipse.trace4cps.tl.cmd-0.2.0-SNAPSHOT.jar";
	path_spec = spec;	//"property.etl";
	path_trace = TRACE;	//"TRACE/TRACE";

}


void call_trace4cps::verify(const int index){

	string com = "java -jar " + java_API + " " + path_spec + " " + path_trace + to_string(index) + ".etf"+ " > IP_verify_result/TRACE" + to_string(index) + "_result.txt";
	system(com.c_str());
	fstream res;
	res.open("IP_verify_result/TRACE" + to_string(index) + "_result.txt", ios::app | ios::out | ios::in);
	string line;
	while(!res.eof()){
		getline(res,line);
		if(line.find("#UNSAT = 0")!=string::npos){
			flag = true;
			break;
		} 
		else if(line.find("#UNSAT =")!=string::npos){
			cout << "Please check trace" << index <<endl;
			flag = false;
			break; 
		} 
	}
	res.close();
	return;
}


