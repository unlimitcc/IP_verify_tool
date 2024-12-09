#include "Extract_Propos.h"

extract_propos::extract_propos(bool use_z3){
	
	Z3_API = use_z3;
}

void extract_propos::get_propos(const string &src_path, 
								const string &IP_name, 
								unordered_map<string,vector<int>> &array_ass, 
								vector<string> &var_exp){
	
	string infile = src_path+"IP_"+IP_name+"_property.ltl";
	int count = 0;
	vector<string> assum;
	var_exp = extractpropos(infile,assum);
	
	//清理多余的符号
	for(string &str : var_exp){
		if(str.find('(') == string::npos){
			if(str.find(')') != string::npos){
				str.replace(str.find(')'), 1, "");
			}
		}
	}
	
	//从assum中提取与初始化相关的信息
	for(string s : assum){
		if(s[0]!='I') continue;
		if(s.find('=')!=string::npos){
			int op = s.find('=');
			string array_name;
			if(s.find('>')!=string::npos || s.find('<')!=string::npos) op--;
			op--;
			array_name = s.substr(1,op-1);
			if(s.find('(')!=string::npos){//二维数组
				s = s.substr(s.find('('),s.find(')')-s.find('(')+1);
				int comma = s.find(',');
				array_ass[array_name].emplace_back(stoi(s.substr(1,comma-1)));
				array_ass[array_name].emplace_back(stoi(s.substr(comma+1,s.length()-comma-1)));
			}else{
				s = s.substr(s.find('=')+1,s.length()-s.find('=')-1);
				array_ass[array_name].emplace_back(stoi(s));	
			}
		}
	}
	propos_file.open(src_path+"IP_"+IP_name+"_propos.txt", ios::out|ios::in);
   	for(string pro : var_exp){
   		propos_file<<"p"<<++count<<":"<<pro<<endl;
   		string p_count = "p" + to_string(count);
   		trace_propos[pro] = p_count;
   	}
   	propos_file.close();

	//将包含next操作符的放到起始位置
	//若不修改next命题的位置，可能导致将命题中的变量替换为真值时出现错误，排序的过程放在主过程
	//stable_partition(var_exp.begin()+assum.size(), var_exp.end(), containsNext);
	if(Z3_API){
		property_infile.open(infile);
		if(!property_infile){
			throw runtime_error("错误 : 未正确指定待验证IP名称!" + IP_name);
		}
		//property_infile.open(infile);
		
		//string line;
		while(!property_infile.eof()){
			string line;
			getline(property_infile,line);
			/*if(line.find("Assumptions")!=string::npos) z3_propos.emplace_back("Assumptions");
			if(line.find("Guarantee0")!=string::npos){
				z3_propos.emplace_back("Guarantee0");
				break;
			}else if(line.find("Guarantee")!=string::npos){
				int st = line.find("Guarantee"), ed = st + 9;
				while(line[ed]>='0' && line[ed]<='9'){
					ed++;
				}
				string guar = line.substr(st,ed-st);
				z3_propos.emplace_back(guar);
			}*/
			if(line.find("Z3_SMT")!=string::npos) {
				z3_propos.emplace_back("Assumptions");
			}
		}
		property_infile.close();
	}
}

void extract_propos::get_propos_next(const map<string, pair<string, string>> &next, const vector<string> &var_exp){

	for(int i=0; i<var_exp.size(); i++){
		if(var_exp[i].find("next(")==string::npos) continue;
		string exp = var_exp[i];
		for(auto it=next.begin(); it!=next.end(); it++){
			if(exp.find("next("+it->first)!=string::npos && !ex_next[it->first]){//命题中存在next(var)此类表达式
				ex_next[it->first] = 1;
			}
		}
	}
}

// 操作符优先级
std::map<std::string, int> precedence = {
    {"G", 4}, {"F", 4}, {"U", 3},
    {"->", 2}, {"&", 1}, {"|", 1}, {"!", 5}
};

// 定义表达式节点
struct Node {
    std::string value;
    Node* left;
    Node* right;

    Node(std::string val) : value(val), left(nullptr), right(nullptr) {}
};

// 判断是否是操作符
bool isOperator(const std::string& token) {
    return precedence.find(token) != precedence.end();
}

// 判断是否是原子命题
bool isProposition(const std::string& token) {
    return !isOperator(token) && token != "(" && token != ")";
}


std::vector<std::string> tokenize(const std::string& expr) {
    std::vector<std::string> tokens;
    std::regex token_regex(R"((\w+|->|[&|!()U]|\d+))");
    auto words_begin = std::sregex_iterator(expr.begin(), expr.end(), token_regex);
    auto words_end = std::sregex_iterator();

    for (auto it = words_begin; it != words_end; ++it) {
        tokens.push_back(it->str());
    }
    return tokens;
}


// 中缀表达式转后缀表达式（逆波兰表达式）
std::vector<std::string> infixToPostfix(const std::vector<std::string>& tokens) {
    std::vector<std::string> output;
    std::stack<std::string> opStack;

    for (const std::string& token : tokens) {
        if (isProposition(token)) {
            output.push_back(token);
        } else if (token == "(") {
            opStack.push(token);
        } else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.pop(); // 弹出左括号
        } else if (isOperator(token)) {
            while (!opStack.empty() && isOperator(opStack.top()) &&
                   precedence[opStack.top()] >= precedence[token]) {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
    }

    // 清空栈中剩余的操作符
    while (!opStack.empty()) {
        output.push_back(opStack.top());
        opStack.pop();
    }

    return output;
}

// 通过后缀表达式构建语法树
Node* buildSyntaxTree(const std::vector<std::string>& postfix) {
    std::stack<Node*> nodeStack;

    for (const std::string& token : postfix) {
        if (isProposition(token)) {
            nodeStack.push(new Node(token));
        } else {
            Node* node = new Node(token);
            if (token == "G" || token == "F" || token == "!") {
                node->right = nodeStack.top();
                nodeStack.pop();
            } else {
                node->right = nodeStack.top(); nodeStack.pop();
                node->left = nodeStack.top(); nodeStack.pop();
            }
            nodeStack.push(node);
        }
    }

    return nodeStack.top();
}

// 根据语法树转换成目标格式的字符串
std::string convertToReadable(Node* root) {
    if (!root) return "";

    std::string left = convertToReadable(root->left);
    std::string right = convertToReadable(root->right);

    // 按不同的操作符生成合适的输出
    if (root->value == "G") {
        return "globally " + right;  // 不添加多余括号
    } else if (root->value == "F") {
        return "finally " + right;  // 不添加多余括号
    } else if (root->value == "U") {
        return "until " + right + " we have that " + left;
    } else if (root->value == "->") {
        return "if " + left + " then " + right;
    } else if (root->value == "&") {
        return "(" + left + " and " + right + ")";  // and操作添加括号
    } else if (root->value == "|") {
        return "(" + left + " or " + right + ")";   // or操作添加括号
    } else if (root->value == "!") {
        return "not " + right;  // 处理not操作
    } else {
        return root->value;  // 原子命题直接返回
    }
}

void extract_propos::trans_TRACE_property(const string &src_path, const string &IP_name){

	string infile = src_path+"IP_"+IP_name+"_property.ltl";
	string trace_file = src_path+"property.etl";
	TRACE_property_file.open(trace_file, ios::out);
	property_infile.open(infile);
	
	//固定输出
	for(auto prop : trace_propos){
		TRACE_property_file << "def " << prop.second << ": " << "{" << "\'" << prop.second << "\' = \'true\'}" << "//" << prop.first << endl; 
	}
	TRACE_property_file << "signal s1 : {\'name\' = \'s1\'}" << endl;
	//count记录性质数量
	int count = 0;
	while(!property_infile.eof()){
		//trace_property表示TRACE的性质
		string trace_property;
		string line;
		getline(property_infile,line);
		if(line.length() == 0) break;
		//去掉空格
		line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
		string check = "ltl" + to_string(++count); 
		for(auto str : trace_propos){
			while(line.find(str.first) != string::npos){
				int temp = line.find(str.first);
				string p = "("+str.second+")";
				line.replace(temp, str.first.length(), p);
			}
		}
		auto tokens = tokenize(line);
		auto postfix = infixToPostfix(tokens);
		Node* root = buildSyntaxTree(postfix);
		string result = convertToReadable(root);
		trace_property = "check " + check + " : " + "if s1 >= 1.0 then not " + result;
		TRACE_property_file << trace_property << endl;
		cout << "trans result : " << trace_property << endl;
	}
	property_infile.close();
	TRACE_property_file.close();
	cout << "parse done" << endl;
	return;
}
