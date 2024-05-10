
// Generated from NC.g4 by ANTLR 4.13.1


#include "NCVisitor.h"

#include "NCParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct NCParserStaticData final {
  NCParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  NCParserStaticData(const NCParserStaticData&) = delete;
  NCParserStaticData(NCParserStaticData&&) = delete;
  NCParserStaticData& operator=(const NCParserStaticData&) = delete;
  NCParserStaticData& operator=(NCParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ncParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
NCParserStaticData *ncParserStaticData = nullptr;

void ncParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ncParserStaticData != nullptr) {
    return;
  }
#else
  assert(ncParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<NCParserStaticData>(
    std::vector<std::string>{
      "prog", "stat", "expr"
    },
    std::vector<std::string>{
      "", "'='", "'('", "')'", "", "", "", "", "'*'", "'/'", "'%'", "'+'", 
      "'-'", "'^'"
    },
    std::vector<std::string>{
      "", "", "", "", "ID", "NUM", "NEWLINE", "WS", "MUL", "DIV", "MOD", 
      "ADD", "SUB", "POW"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,13,53,2,0,7,0,2,1,7,1,2,2,7,2,1,0,4,0,8,8,0,11,0,12,0,9,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,21,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,40,8,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,5,2,48,8,2,10,2,12,2,51,9,2,1,2,0,1,4,3,0,2,4,0,2,1,0,8,10,1,0,11,12,
  	58,0,7,1,0,0,0,2,20,1,0,0,0,4,39,1,0,0,0,6,8,3,2,1,0,7,6,1,0,0,0,8,9,
  	1,0,0,0,9,7,1,0,0,0,9,10,1,0,0,0,10,1,1,0,0,0,11,12,3,4,2,0,12,13,5,6,
  	0,0,13,21,1,0,0,0,14,15,5,4,0,0,15,16,5,1,0,0,16,17,3,4,2,0,17,18,5,6,
  	0,0,18,21,1,0,0,0,19,21,5,6,0,0,20,11,1,0,0,0,20,14,1,0,0,0,20,19,1,0,
  	0,0,21,3,1,0,0,0,22,23,6,2,-1,0,23,24,5,2,0,0,24,25,3,4,2,0,25,26,5,13,
  	0,0,26,27,3,4,2,0,27,28,5,3,0,0,28,40,1,0,0,0,29,40,5,5,0,0,30,31,5,2,
  	0,0,31,32,5,12,0,0,32,33,5,5,0,0,33,40,5,3,0,0,34,40,5,4,0,0,35,36,5,
  	2,0,0,36,37,3,4,2,0,37,38,5,3,0,0,38,40,1,0,0,0,39,22,1,0,0,0,39,29,1,
  	0,0,0,39,30,1,0,0,0,39,34,1,0,0,0,39,35,1,0,0,0,40,49,1,0,0,0,41,42,10,
  	6,0,0,42,43,7,0,0,0,43,48,3,4,2,7,44,45,10,5,0,0,45,46,7,1,0,0,46,48,
  	3,4,2,6,47,41,1,0,0,0,47,44,1,0,0,0,48,51,1,0,0,0,49,47,1,0,0,0,49,50,
  	1,0,0,0,50,5,1,0,0,0,51,49,1,0,0,0,5,9,20,39,47,49
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ncParserStaticData = staticData.release();
}

}

NCParser::NCParser(TokenStream *input) : NCParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

NCParser::NCParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  NCParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ncParserStaticData->atn, ncParserStaticData->decisionToDFA, ncParserStaticData->sharedContextCache, options);
}

NCParser::~NCParser() {
  delete _interpreter;
}

const atn::ATN& NCParser::getATN() const {
  return *ncParserStaticData->atn;
}

std::string NCParser::getGrammarFileName() const {
  return "NC.g4";
}

const std::vector<std::string>& NCParser::getRuleNames() const {
  return ncParserStaticData->ruleNames;
}

const dfa::Vocabulary& NCParser::getVocabulary() const {
  return ncParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView NCParser::getSerializedATN() const {
  return ncParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

NCParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NCParser::StatContext *> NCParser::ProgContext::stat() {
  return getRuleContexts<NCParser::StatContext>();
}

NCParser::StatContext* NCParser::ProgContext::stat(size_t i) {
  return getRuleContext<NCParser::StatContext>(i);
}


size_t NCParser::ProgContext::getRuleIndex() const {
  return NCParser::RuleProg;
}


std::any NCParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

NCParser::ProgContext* NCParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, NCParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(7); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(6);
      stat();
      setState(9); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 116) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

NCParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t NCParser::StatContext::getRuleIndex() const {
  return NCParser::RuleStat;
}

void NCParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BlankContext ------------------------------------------------------------------

tree::TerminalNode* NCParser::BlankContext::NEWLINE() {
  return getToken(NCParser::NEWLINE, 0);
}

NCParser::BlankContext::BlankContext(StatContext *ctx) { copyFrom(ctx); }


std::any NCParser::BlankContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitBlank(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintExprContext ------------------------------------------------------------------

NCParser::ExprContext* NCParser::PrintExprContext::expr() {
  return getRuleContext<NCParser::ExprContext>(0);
}

tree::TerminalNode* NCParser::PrintExprContext::NEWLINE() {
  return getToken(NCParser::NEWLINE, 0);
}

NCParser::PrintExprContext::PrintExprContext(StatContext *ctx) { copyFrom(ctx); }


std::any NCParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* NCParser::AssignContext::ID() {
  return getToken(NCParser::ID, 0);
}

NCParser::ExprContext* NCParser::AssignContext::expr() {
  return getRuleContext<NCParser::ExprContext>(0);
}

tree::TerminalNode* NCParser::AssignContext::NEWLINE() {
  return getToken(NCParser::NEWLINE, 0);
}

NCParser::AssignContext::AssignContext(StatContext *ctx) { copyFrom(ctx); }


std::any NCParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
NCParser::StatContext* NCParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 2, NCParser::RuleStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(20);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<NCParser::PrintExprContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(11);
      expr(0);
      setState(12);
      match(NCParser::NEWLINE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<NCParser::AssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(14);
      match(NCParser::ID);
      setState(15);
      match(NCParser::T__0);
      setState(16);
      expr(0);
      setState(17);
      match(NCParser::NEWLINE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NCParser::BlankContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(19);
      match(NCParser::NEWLINE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

NCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t NCParser::ExprContext::getRuleIndex() const {
  return NCParser::RuleExpr;
}

void NCParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParensContext ------------------------------------------------------------------

NCParser::ExprContext* NCParser::ParensContext::expr() {
  return getRuleContext<NCParser::ExprContext>(0);
}

NCParser::ParensContext::ParensContext(ExprContext *ctx) { copyFrom(ctx); }


std::any NCParser::ParensContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitParens(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivModContext ------------------------------------------------------------------

std::vector<NCParser::ExprContext *> NCParser::MulDivModContext::expr() {
  return getRuleContexts<NCParser::ExprContext>();
}

NCParser::ExprContext* NCParser::MulDivModContext::expr(size_t i) {
  return getRuleContext<NCParser::ExprContext>(i);
}

tree::TerminalNode* NCParser::MulDivModContext::MUL() {
  return getToken(NCParser::MUL, 0);
}

tree::TerminalNode* NCParser::MulDivModContext::DIV() {
  return getToken(NCParser::DIV, 0);
}

tree::TerminalNode* NCParser::MulDivModContext::MOD() {
  return getToken(NCParser::MOD, 0);
}

NCParser::MulDivModContext::MulDivModContext(ExprContext *ctx) { copyFrom(ctx); }


std::any NCParser::MulDivModContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitMulDivMod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinusValContext ------------------------------------------------------------------

tree::TerminalNode* NCParser::MinusValContext::SUB() {
  return getToken(NCParser::SUB, 0);
}

tree::TerminalNode* NCParser::MinusValContext::NUM() {
  return getToken(NCParser::NUM, 0);
}

NCParser::MinusValContext::MinusValContext(ExprContext *ctx) { copyFrom(ctx); }


std::any NCParser::MinusValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitMinusVal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubContext ------------------------------------------------------------------

std::vector<NCParser::ExprContext *> NCParser::AddSubContext::expr() {
  return getRuleContexts<NCParser::ExprContext>();
}

NCParser::ExprContext* NCParser::AddSubContext::expr(size_t i) {
  return getRuleContext<NCParser::ExprContext>(i);
}

tree::TerminalNode* NCParser::AddSubContext::ADD() {
  return getToken(NCParser::ADD, 0);
}

tree::TerminalNode* NCParser::AddSubContext::SUB() {
  return getToken(NCParser::SUB, 0);
}

NCParser::AddSubContext::AddSubContext(ExprContext *ctx) { copyFrom(ctx); }


std::any NCParser::AddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumContext ------------------------------------------------------------------

tree::TerminalNode* NCParser::NumContext::NUM() {
  return getToken(NCParser::NUM, 0);
}

NCParser::NumContext::NumContext(ExprContext *ctx) { copyFrom(ctx); }


std::any NCParser::NumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitNum(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowContext ------------------------------------------------------------------

std::vector<NCParser::ExprContext *> NCParser::PowContext::expr() {
  return getRuleContexts<NCParser::ExprContext>();
}

NCParser::ExprContext* NCParser::PowContext::expr(size_t i) {
  return getRuleContext<NCParser::ExprContext>(i);
}

tree::TerminalNode* NCParser::PowContext::POW() {
  return getToken(NCParser::POW, 0);
}

NCParser::PowContext::PowContext(ExprContext *ctx) { copyFrom(ctx); }


std::any NCParser::PowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitPow(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdContext ------------------------------------------------------------------

tree::TerminalNode* NCParser::IdContext::ID() {
  return getToken(NCParser::ID, 0);
}

NCParser::IdContext::IdContext(ExprContext *ctx) { copyFrom(ctx); }


std::any NCParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NCVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}

NCParser::ExprContext* NCParser::expr() {
   return expr(0);
}

NCParser::ExprContext* NCParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  NCParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  NCParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, NCParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(39);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PowContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(23);
      match(NCParser::T__1);
      setState(24);
      expr(0);
      setState(25);
      antlrcpp::downCast<PowContext *>(_localctx)->op = match(NCParser::POW);
      setState(26);
      expr(0);
      setState(27);
      match(NCParser::T__2);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<NumContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(29);
      match(NCParser::NUM);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MinusValContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(30);
      match(NCParser::T__1);
      setState(31);
      match(NCParser::SUB);
      setState(32);
      match(NCParser::NUM);
      setState(33);
      match(NCParser::T__2);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<IdContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(34);
      match(NCParser::ID);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(35);
      match(NCParser::T__1);
      setState(36);
      expr(0);
      setState(37);
      match(NCParser::T__2);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(49);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(47);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivModContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(41);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(42);
          antlrcpp::downCast<MulDivModContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1792) != 0))) {
            antlrcpp::downCast<MulDivModContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(43);
          expr(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(44);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(45);
          antlrcpp::downCast<AddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == NCParser::ADD

          || _la == NCParser::SUB)) {
            antlrcpp::downCast<AddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(46);
          expr(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(51);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool NCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool NCParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

void NCParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ncParserInitialize();
#else
  ::antlr4::internal::call_once(ncParserOnceFlag, ncParserInitialize);
#endif
}
