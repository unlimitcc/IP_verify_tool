
// Generated from contract.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  contractParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, ASS = 3, GUA = 4, LOP = 5, TOP = 6, QUAN = 7, VALUE = 8, 
    VAR = 9, ADD = 10, SUB = 11, MUL = 12, DIV = 13, MOD = 14, POW = 15, 
    RANGE = 16, COMP = 17, COLON = 18, COMMA = 19, POINT = 20, SKIP1 = 21, 
    SKIP2 = 22, NEWLINE = 23
  };

  enum {
    RuleFile = 0, RuleInit = 1, RuleStat = 2, RuleCond = 3, RulePropos = 4, 
    RuleCom = 5, RuleQuan = 6, RuleExpr = 7
  };

  explicit contractParser(antlr4::TokenStream *input);

  contractParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~contractParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FileContext;
  class InitContext;
  class StatContext;
  class CondContext;
  class ProposContext;
  class ComContext;
  class QuanContext;
  class ExprContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    antlr4::tree::TerminalNode *ASS();
    InitContext *init();
    std::vector<antlr4::tree::TerminalNode *> GUA();
    antlr4::tree::TerminalNode* GUA(size_t i);
    std::vector<StatContext *> stat();
    StatContext* stat(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  InitContext : public antlr4::ParserRuleContext {
  public:
    InitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InitContext *> init();
    InitContext* init(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOP();
    antlr4::tree::TerminalNode* LOP(size_t i);
    std::vector<CondContext *> cond();
    CondContext* cond(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InitContext* init();

  class  StatContext : public antlr4::ParserRuleContext {
  public:
    StatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatContext *> stat();
    StatContext* stat(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOP();
    antlr4::tree::TerminalNode* LOP(size_t i);
    std::vector<ProposContext *> propos();
    ProposContext* propos(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatContext* stat();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ComContext *> com();
    ComContext* com(size_t i);
    std::vector<QuanContext *> quan();
    QuanContext* quan(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOP();
    antlr4::tree::TerminalNode* LOP(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CondContext* cond();

  class  ProposContext : public antlr4::ParserRuleContext {
  public:
    ProposContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ComContext *> com();
    ComContext* com(size_t i);
    std::vector<QuanContext *> quan();
    QuanContext* quan(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOP();
    antlr4::tree::TerminalNode* LOP(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProposContext* propos();

  class  ComContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *op = nullptr;
    ComContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *COMP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ComContext* com();

  class  QuanContext : public antlr4::ParserRuleContext {
  public:
    QuanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUAN();
    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode* VAR(size_t i);
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *RANGE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QuanContext* quan();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *op = nullptr;
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *POW();
    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode* VAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RANGE();
    antlr4::tree::TerminalNode* RANGE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *VALUE();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

