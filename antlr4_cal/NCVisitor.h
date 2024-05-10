
// Generated from NC.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "NCParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by NCParser.
 */
class  NCVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by NCParser.
   */
    virtual std::any visitProg(NCParser::ProgContext *context) = 0;

    virtual std::any visitPrintExpr(NCParser::PrintExprContext *context) = 0;

    virtual std::any visitAssign(NCParser::AssignContext *context) = 0;

    virtual std::any visitBlank(NCParser::BlankContext *context) = 0;

    virtual std::any visitParens(NCParser::ParensContext *context) = 0;

    virtual std::any visitMulDivMod(NCParser::MulDivModContext *context) = 0;

    virtual std::any visitMinusVal(NCParser::MinusValContext *context) = 0;

    virtual std::any visitAddSub(NCParser::AddSubContext *context) = 0;

    virtual std::any visitNum(NCParser::NumContext *context) = 0;

    virtual std::any visitPow(NCParser::PowContext *context) = 0;

    virtual std::any visitId(NCParser::IdContext *context) = 0;


};

