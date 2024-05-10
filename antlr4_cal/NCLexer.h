
// Generated from NC.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  NCLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, ID = 4, NUM = 5, NEWLINE = 6, WS = 7, 
    MUL = 8, DIV = 9, MOD = 10, ADD = 11, SUB = 12, POW = 13
  };

  explicit NCLexer(antlr4::CharStream *input);

  ~NCLexer() override;


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

