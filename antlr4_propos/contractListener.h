
// Generated from contract.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "contractParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by contractParser.
 */
class  contractListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(contractParser::FileContext *ctx) = 0;
  virtual void exitFile(contractParser::FileContext *ctx) = 0;

  virtual void enterLtl(contractParser::LtlContext *ctx) = 0;
  virtual void exitLtl(contractParser::LtlContext *ctx) = 0;

  virtual void enterPropos(contractParser::ProposContext *ctx) = 0;
  virtual void exitPropos(contractParser::ProposContext *ctx) = 0;

  virtual void enterAtomic_propos(contractParser::Atomic_proposContext *ctx) = 0;
  virtual void exitAtomic_propos(contractParser::Atomic_proposContext *ctx) = 0;

  virtual void enterQuan(contractParser::QuanContext *ctx) = 0;
  virtual void exitQuan(contractParser::QuanContext *ctx) = 0;

  virtual void enterExpr(contractParser::ExprContext *ctx) = 0;
  virtual void exitExpr(contractParser::ExprContext *ctx) = 0;


};

