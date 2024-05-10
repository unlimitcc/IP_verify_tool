/*EvalVisitor.h*/
#pragma once
#include "NCBaseVisitor.h"
#include <map>

/*继承默认访问器类并对其方法进行重写*/
class EvalVisitor : public NCBaseVisitor 
{
private:
	std::map<std::string, std::any> memory;
public:
	double res = 0;
    /* 对应语法文件中ID '=' expr NEWLINE */
    virtual std::any visitAssign(NCParser::AssignContext* ctx) ; /*函数名是由 visit + 语法文件中#Label首字符大写组成*/
    /* 对应语法文件中expr NEWLINE */
    virtual std::any visitPrintExpr(NCParser::PrintExprContext* ctx) ;
    /* 对应语法文件中NUM */
    virtual std::any visitNum(NCParser::NumContext *ctx);
    /* 对应语法文件中('-'NUM) */
    virtual std::any visitMinusVal(NCParser::MinusValContext *ctx);
    /* 对应语法文件中Id */
    virtual std::any visitId(NCParser::IdContext* ctx);
    /* 对应语法文件中expr op=('-'|'+') expr */
    virtual std::any visitAddSub(NCParser::AddSubContext* ctx);
    /* 对应语法文件中expr op=('*'|'/') expr */
    virtual std::any visitMulDivMod(NCParser::MulDivModContext* ctx);
    /* 对应语法文件中'(' expr ')' */
    virtual std::any visitParens(NCParser::ParensContext* ctx);
    /* 对应语法文件中expr op=('^') expr */
    virtual std::any visitPow(NCParser::PowContext *ctx);
};
