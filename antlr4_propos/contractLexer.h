
// Generated from contract.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  contractLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, ASS = 3, GUA = 4, LOP = 5, TOP = 6, QUAN = 7, VALUE = 8, 
    VAR = 9, ADD = 10, SUB = 11, MUL = 12, DIV = 13, MOD = 14, POW = 15, 
    RANGE = 16, COMP = 17, COLON = 18, COMMA = 19, SKIP1 = 20, SKIP2 = 21, 
    NEWLINE = 22
  };

  explicit contractLexer(antlr4::CharStream *input);

  ~contractLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

