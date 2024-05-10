/*main.cpp*/
#include <iostream>
#include "antlr4-runtime.h"
#include "NCLexer.h"
#include "NCParser.h"
#include "EvalVisitor.h"
#include <string>

#pragma execution_character_set("utf-8")
#pragma comment(lib, "antlr4-runtime.lib") //安装方法中静态库引用
using namespace antlr4;

int main(int argc, const char* argv[]) {
    ANTLRInputStream input(std::cin);
    NCLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    NCParser parser(&tokens);
    tree::ParseTree* tree = parser.prog(); //parser.grog其中prog就是语法文件的起始规则名称
    EvalVisitor eval; //实例化自定义的访问器类
    eval.visit(tree); //通过visit()函数开始遍历语法树
    return 0;
}
