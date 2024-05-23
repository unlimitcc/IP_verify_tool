/*extractpropos.cpp*/
#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "contractLexer.h"
#include "contractParser.h"
#include "contractBaseListener.h"
#include <vector>

#pragma execution_character_set("utf-8")
#pragma comment(lib, "antlr4-runtime.lib") //安装方法中静态库引用
using namespace antlr4;

class demoListener: public contractBaseListener{
	public:
		std::vector<std::string> propos;
	public:
		void enterPropos(contractParser::ProposContext* ctx){
			if(std::find(propos.begin(),propos.end(),ctx->getText())==propos.end()){
				propos.emplace_back(ctx->getText());
				std::cout<<ctx->getText()<<std::endl;
			}
		}
};

/*
std::vector<std::string> extractpropos(std::string input_file) {
	std::ifstream property_file;
	property_file.open(input_file,std::ios::app | std::ios::out | std::ios::in);
    ANTLRInputStream input(property_file);
    contractLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
   	contractParser parser(&tokens);
   	tree::ParseTree* tree = parser.file();
   	demoListener demo;
   	tree::ParseTreeWalker::DEFAULT.walk(&demo, tree);
    return demo.propos;
}
*/
int main(int argc, const char* argv[]) {
	//std::ifstream property_file;
	//property_file.open(input_file,std::ios::app | std::ios::out | std::ios::in);
    ANTLRInputStream input(std::cin);
    contractLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
   	contractParser parser(&tokens);
   	tree::ParseTree* tree = parser.file();
   	demoListener demo;
   	tree::ParseTreeWalker::DEFAULT.walk(&demo, tree);
    return 0;
}


