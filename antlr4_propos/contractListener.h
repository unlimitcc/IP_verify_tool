
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

  virtual void enterInit(contractParser::InitContext *ctx) = 0;
  virtual void exitInit(contractParser::InitContext *ctx) = 0;

  virtual void enterStat(contractParser::StatContext *ctx) = 0;
  virtual void exitStat(contractParser::StatContext *ctx) = 0;

  virtual void enterCond(contractParser::CondContext *ctx) = 0;
  virtual void exitCond(contractParser::CondContext *ctx) = 0;

  virtual void enterPropos(contractParser::ProposContext *ctx) = 0;
  virtual void exitPropos(contractParser::ProposContext *ctx) = 0;

  virtual void enterCom(contractParser::ComContext *ctx) = 0;
  virtual void exitCom(contractParser::ComContext *ctx) = 0;

  virtual void enterQuan(contractParser::QuanContext *ctx) = 0;
  virtual void exitQuan(contractParser::QuanContext *ctx) = 0;

  virtual void enterExpr(contractParser::ExprContext *ctx) = 0;
  virtual void exitExpr(contractParser::ExprContext *ctx) = 0;


};

