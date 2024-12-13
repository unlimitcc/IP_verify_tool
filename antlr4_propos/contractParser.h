
// Generated from contract.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  contractParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, LOP = 12, QUAN = 13, VALUE = 14, 
    VAR = 15, ARRAY = 16, ADD = 17, SUB = 18, MUL = 19, DIV = 20, MOD = 21, 
    POW = 22, RANGE = 23, COMP = 24, COLON = 25, COMMA = 26, SKIP1 = 27, 
    NEWLINE = 28
  };

  enum {
    RuleFile = 0, RuleLtl = 1, RulePropos = 2, RuleAtomic_propos = 3, RuleQuan = 4, 
    RuleExpr = 5
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
  class LtlContext;
  class ProposContext;
  class Atomic_proposContext;
  class QuanContext;
  class ExprContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<LtlContext *> ltl();
    LtlContext* ltl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  LtlContext : public antlr4::ParserRuleContext {
  public:
    LtlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProposContext *propos();
    std::vector<LtlContext *> ltl();
    LtlContext* ltl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LtlContext* ltl();
  LtlContext* ltl(int precedence);
  class  ProposContext : public antlr4::ParserRuleContext {
  public:
    ProposContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Atomic_proposContext *atomic_propos();
    QuanContext *quan();
    antlr4::tree::TerminalNode *COLON();
    std::vector<ProposContext *> propos();
    ProposContext* propos(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProposContext* propos();
  ProposContext* propos(int precedence);
  class  Atomic_proposContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *op = nullptr;
    Atomic_proposContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *COMP();
    QuanContext *quan();
    antlr4::tree::TerminalNode *COLON();
    std::vector<Atomic_proposContext *> atomic_propos();
    Atomic_proposContext* atomic_propos(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOP();
    antlr4::tree::TerminalNode* LOP(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Atomic_proposContext* atomic_propos();

  class  QuanContext : public antlr4::ParserRuleContext {
  public:
    QuanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QUAN();
    antlr4::tree::TerminalNode* QUAN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode* VAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    QuanContext *quan();

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
    antlr4::tree::TerminalNode *VAR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *VALUE();
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *ADD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool ltlSempred(LtlContext *_localctx, size_t predicateIndex);
  bool proposSempred(ProposContext *_localctx, size_t predicateIndex);
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

