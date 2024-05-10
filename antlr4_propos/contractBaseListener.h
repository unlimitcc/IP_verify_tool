
// Generated from contract.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "contractListener.h"


/**
 * This class provides an empty implementation of contractListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  contractBaseListener : public contractListener {
public:

  virtual void enterFile(contractParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(contractParser::FileContext * /*ctx*/) override { }

  virtual void enterInit(contractParser::InitContext * /*ctx*/) override { }
  virtual void exitInit(contractParser::InitContext * /*ctx*/) override { }

  virtual void enterStat(contractParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(contractParser::StatContext * /*ctx*/) override { }

  virtual void enterCond(contractParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(contractParser::CondContext * /*ctx*/) override { }

  virtual void enterPropos(contractParser::ProposContext * /*ctx*/) override { }
  virtual void exitPropos(contractParser::ProposContext * /*ctx*/) override { }

  virtual void enterCom(contractParser::ComContext * /*ctx*/) override { }
  virtual void exitCom(contractParser::ComContext * /*ctx*/) override { }

  virtual void enterQuan(contractParser::QuanContext * /*ctx*/) override { }
  virtual void exitQuan(contractParser::QuanContext * /*ctx*/) override { }

  virtual void enterExpr(contractParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(contractParser::ExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

