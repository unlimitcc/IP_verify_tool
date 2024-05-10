/*EvalVisitor.cpp*/
#include "EvalVisitor.h"
#include <cmath>
#include <typeinfo>

std::any EvalVisitor::visitAssign(NCParser::AssignContext* ctx)
{
    std::string s = ctx->ID()->getText();   //其中ctx表示标签所代表的语法树,ID是此语法树中的ID分支
    std::any value = visit(ctx->expr()); //因为expr不是一个终结符，调用visit()访问expr的值
    memory[s] = value;
    return value;
}

std::any EvalVisitor::visitPrintExpr(NCParser::PrintExprContext* ctx)
{
    std::any value = visit(ctx->expr());  //因为expr不是一个终结符，调用visit()访问expr的值
    if(value.type()==typeid(std::string)) std::cout << std::any_cast<std::string>(value) << std::endl;
    else {
    	res = std::any_cast<double>(value);
    	//std::cout <<std::any_cast<double>(value) << std::endl;
    }
    return 0;
}

std::any EvalVisitor::visitNum(NCParser::NumContext *ctx)
{
    std::string s = ctx->NUM()->getText(); //终结符getText()返回值
    double value = stod(s);
    return std::any(value);
}

std::any EvalVisitor::visitMinusVal(NCParser::MinusValContext *ctx)
{
    std::string s = ctx->NUM()->getText(); //终结符getText()返回值
    double value = stod(s);
    return std::any(-1*value);
}

std::any EvalVisitor::visitId(NCParser::IdContext* ctx)
{
    std::string id = ctx->ID()->getText();
    if(memory.find(id)!=memory.end()) return memory[id];
    else return 0;
    //由于没有写错误检查如果没有对id进行赋值 就会返回为0;
}

std::any EvalVisitor::visitAddSub(NCParser::AddSubContext* ctx)
{
    std::any l = visit(ctx->expr(0)); //暂时理解为addsub语法中,含有两个expr，此处相当于按索引值判定左右子树
    std::any r = visit(ctx->expr(1));
    if (ctx->op->getType() == NCParser::ADD) return std::any_cast<double>(l) + std::any_cast<double>(r);
    //语法中op属性和词法文件中终结符ADD进行比对
    else return std::any_cast<double>(l) - std::any_cast<double>(r);
}

std::any EvalVisitor::visitMulDivMod(NCParser::MulDivModContext *ctx)
{
    std::any l = visit(ctx->expr(0));
    std::any r = visit(ctx->expr(1));
    if (ctx->op->getType() == NCParser::MUL) return std::any_cast<double>(l) * std::any_cast<double>(r);
    else if(ctx->op->getType() == NCParser::DIV){
    	if(std::any_cast<double>(r) == 0) std::cout<< "!ERROR: divisor cannot be zero." <<std::endl;
    	else return std::any_cast<double>(l) / std::any_cast<double>(r);
    }
    else{
    	int i_l = int(std::any_cast<double>(l));
    	int i_r = int(std::any_cast<double>(r));
   		if(i_l == std::any_cast<double>(l) && i_r == std::any_cast<double>(r)){
   			return std::any(1.0*(i_l % i_r));
   		}else{
    		std::cout<< "Mod \'%\' operations should be integer." << std::endl;
    		return 0;
    	}
    }
    return 0;
}

std::any EvalVisitor::visitParens(NCParser::ParensContext* ctx)
{
    return visit(ctx->expr()); //返回对应值 
}

std::any EvalVisitor::visitPow(NCParser::PowContext *ctx)
{
	std::any l = visit(ctx->expr(0));
	std::any r = visit(ctx->expr(1));
	return pow(std::any_cast<double>(l),std::any_cast<double>(r));
}

