
// Generated from NC.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "NCVisitor.h"


/**
 * This class provides an empty implementation of NCVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  NCBaseVisitor : public NCVisitor {
public:

  virtual std::any visitProg(NCParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintExpr(NCParser::PrintExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(NCParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlank(NCParser::BlankContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParens(NCParser::ParensContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulDivMod(NCParser::MulDivModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMinusVal(NCParser::MinusValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSub(NCParser::AddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNum(NCParser::NumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPow(NCParser::PowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitId(NCParser::IdContext *ctx) override {
    return visitChildren(ctx);
  }


};

