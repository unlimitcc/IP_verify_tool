
// Generated from contract.g4 by ANTLR 4.13.1


#include "contractListener.h"

#include "contractParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ContractParserStaticData final {
  ContractParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ContractParserStaticData(const ContractParserStaticData&) = delete;
  ContractParserStaticData(ContractParserStaticData&&) = delete;
  ContractParserStaticData& operator=(const ContractParserStaticData&) = delete;
  ContractParserStaticData& operator=(ContractParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag contractParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ContractParserStaticData *contractParserStaticData = nullptr;

void contractParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (contractParserStaticData != nullptr) {
    return;
  }
#else
  assert(contractParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ContractParserStaticData>(
    std::vector<std::string>{
      "file", "ltl", "propos", "atomic_propos", "quan", "expr"
    },
    std::vector<std::string>{
      "", "'&'", "'|'", "'->'", "'<->'", "'!'", "'X'", "'G'", "'F'", "'U'", 
      "'('", "')'", "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", 
      "'^'", "", "", "':'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "LOP", "QUAN", "VALUE", 
      "VAR", "ARRAY", "ADD", "SUB", "MUL", "DIV", "MOD", "POW", "RANGE", 
      "COMP", "COLON", "COMMA", "SKIP1", "NEWLINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,28,185,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,1,
  	0,4,0,16,8,0,11,0,12,0,17,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,3,1,36,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,5,1,53,8,1,10,1,12,1,56,9,1,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,3,2,68,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,5,2,82,8,2,10,2,12,2,85,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,5,3,98,8,3,10,3,12,3,101,9,3,1,3,1,3,1,3,3,3,106,8,3,1,4,
  	1,4,1,4,1,4,1,4,5,4,113,8,4,10,4,12,4,116,9,4,1,4,4,4,119,8,4,11,4,12,
  	4,120,1,4,1,4,1,4,1,4,3,4,127,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,5,5,141,8,5,10,5,12,5,144,9,5,1,5,1,5,4,5,148,8,5,11,5,12,
  	5,149,1,5,1,5,1,5,1,5,5,5,156,8,5,10,5,12,5,159,9,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,172,8,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,180,
  	8,5,10,5,12,5,183,9,5,1,5,0,3,2,4,10,6,0,2,4,6,8,10,0,2,1,0,19,21,1,0,
  	17,18,212,0,15,1,0,0,0,2,35,1,0,0,0,4,67,1,0,0,0,6,105,1,0,0,0,8,126,
  	1,0,0,0,10,171,1,0,0,0,12,13,3,2,1,0,13,14,5,28,0,0,14,16,1,0,0,0,15,
  	12,1,0,0,0,16,17,1,0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,19,1,0,0,0,19,
  	20,5,0,0,1,20,1,1,0,0,0,21,22,6,1,-1,0,22,36,3,4,2,0,23,24,5,5,0,0,24,
  	36,3,2,1,6,25,26,5,6,0,0,26,36,3,2,1,5,27,28,5,7,0,0,28,36,3,2,1,4,29,
  	30,5,8,0,0,30,36,3,2,1,3,31,32,5,10,0,0,32,33,3,2,1,0,33,34,5,11,0,0,
  	34,36,1,0,0,0,35,21,1,0,0,0,35,23,1,0,0,0,35,25,1,0,0,0,35,27,1,0,0,0,
  	35,29,1,0,0,0,35,31,1,0,0,0,36,54,1,0,0,0,37,38,10,10,0,0,38,39,5,1,0,
  	0,39,53,3,2,1,11,40,41,10,9,0,0,41,42,5,2,0,0,42,53,3,2,1,10,43,44,10,
  	8,0,0,44,45,5,3,0,0,45,53,3,2,1,9,46,47,10,7,0,0,47,48,5,4,0,0,48,53,
  	3,2,1,8,49,50,10,2,0,0,50,51,5,9,0,0,51,53,3,2,1,3,52,37,1,0,0,0,52,40,
  	1,0,0,0,52,43,1,0,0,0,52,46,1,0,0,0,52,49,1,0,0,0,53,56,1,0,0,0,54,52,
  	1,0,0,0,54,55,1,0,0,0,55,3,1,0,0,0,56,54,1,0,0,0,57,58,6,2,-1,0,58,68,
  	3,6,3,0,59,60,3,8,4,0,60,61,5,25,0,0,61,62,3,4,2,2,62,68,1,0,0,0,63,64,
  	5,10,0,0,64,65,3,4,2,0,65,66,5,11,0,0,66,68,1,0,0,0,67,57,1,0,0,0,67,
  	59,1,0,0,0,67,63,1,0,0,0,68,83,1,0,0,0,69,70,10,6,0,0,70,71,5,1,0,0,71,
  	82,3,4,2,7,72,73,10,5,0,0,73,74,5,2,0,0,74,82,3,4,2,6,75,76,10,4,0,0,
  	76,77,5,3,0,0,77,82,3,4,2,5,78,79,10,3,0,0,79,80,5,4,0,0,80,82,3,4,2,
  	4,81,69,1,0,0,0,81,72,1,0,0,0,81,75,1,0,0,0,81,78,1,0,0,0,82,85,1,0,0,
  	0,83,81,1,0,0,0,83,84,1,0,0,0,84,5,1,0,0,0,85,83,1,0,0,0,86,87,3,10,5,
  	0,87,88,5,24,0,0,88,89,3,10,5,0,89,106,1,0,0,0,90,91,5,10,0,0,91,92,3,
  	8,4,0,92,93,5,25,0,0,93,94,5,10,0,0,94,99,3,6,3,0,95,96,5,12,0,0,96,98,
  	3,6,3,0,97,95,1,0,0,0,98,101,1,0,0,0,99,97,1,0,0,0,99,100,1,0,0,0,100,
  	102,1,0,0,0,101,99,1,0,0,0,102,103,5,11,0,0,103,104,5,11,0,0,104,106,
  	1,0,0,0,105,86,1,0,0,0,105,90,1,0,0,0,106,7,1,0,0,0,107,108,5,13,0,0,
  	108,109,5,10,0,0,109,114,5,15,0,0,110,111,5,26,0,0,111,113,5,15,0,0,112,
  	110,1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,117,1,
  	0,0,0,116,114,1,0,0,0,117,119,5,11,0,0,118,107,1,0,0,0,119,120,1,0,0,
  	0,120,118,1,0,0,0,120,121,1,0,0,0,121,127,1,0,0,0,122,123,5,10,0,0,123,
  	124,3,8,4,0,124,125,5,11,0,0,125,127,1,0,0,0,126,118,1,0,0,0,126,122,
  	1,0,0,0,127,9,1,0,0,0,128,129,6,5,-1,0,129,130,5,10,0,0,130,131,3,10,
  	5,0,131,132,5,22,0,0,132,133,3,10,5,0,133,134,5,11,0,0,134,172,1,0,0,
  	0,135,147,5,15,0,0,136,137,5,10,0,0,137,142,3,10,5,0,138,139,5,26,0,0,
  	139,141,3,10,5,0,140,138,1,0,0,0,141,144,1,0,0,0,142,140,1,0,0,0,142,
  	143,1,0,0,0,143,145,1,0,0,0,144,142,1,0,0,0,145,146,5,11,0,0,146,148,
  	1,0,0,0,147,136,1,0,0,0,148,149,1,0,0,0,149,147,1,0,0,0,149,150,1,0,0,
  	0,150,172,1,0,0,0,151,152,5,10,0,0,152,157,3,10,5,0,153,154,5,26,0,0,
  	154,156,3,10,5,0,155,153,1,0,0,0,156,159,1,0,0,0,157,155,1,0,0,0,157,
  	158,1,0,0,0,158,160,1,0,0,0,159,157,1,0,0,0,160,161,5,11,0,0,161,172,
  	1,0,0,0,162,163,5,18,0,0,163,172,5,14,0,0,164,172,5,14,0,0,165,172,5,
  	16,0,0,166,172,5,15,0,0,167,168,5,10,0,0,168,169,3,10,5,0,169,170,5,11,
  	0,0,170,172,1,0,0,0,171,128,1,0,0,0,171,135,1,0,0,0,171,151,1,0,0,0,171,
  	162,1,0,0,0,171,164,1,0,0,0,171,165,1,0,0,0,171,166,1,0,0,0,171,167,1,
  	0,0,0,172,181,1,0,0,0,173,174,10,9,0,0,174,175,7,0,0,0,175,180,3,10,5,
  	10,176,177,10,8,0,0,177,178,7,1,0,0,178,180,3,10,5,9,179,173,1,0,0,0,
  	179,176,1,0,0,0,180,183,1,0,0,0,181,179,1,0,0,0,181,182,1,0,0,0,182,11,
  	1,0,0,0,183,181,1,0,0,0,18,17,35,52,54,67,81,83,99,105,114,120,126,142,
  	149,157,171,179,181
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  contractParserStaticData = staticData.release();
}

}

contractParser::contractParser(TokenStream *input) : contractParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

contractParser::contractParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  contractParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *contractParserStaticData->atn, contractParserStaticData->decisionToDFA, contractParserStaticData->sharedContextCache, options);
}

contractParser::~contractParser() {
  delete _interpreter;
}

const atn::ATN& contractParser::getATN() const {
  return *contractParserStaticData->atn;
}

std::string contractParser::getGrammarFileName() const {
  return "contract.g4";
}

const std::vector<std::string>& contractParser::getRuleNames() const {
  return contractParserStaticData->ruleNames;
}

const dfa::Vocabulary& contractParser::getVocabulary() const {
  return contractParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView contractParser::getSerializedATN() const {
  return contractParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

contractParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* contractParser::FileContext::EOF() {
  return getToken(contractParser::EOF, 0);
}

std::vector<contractParser::LtlContext *> contractParser::FileContext::ltl() {
  return getRuleContexts<contractParser::LtlContext>();
}

contractParser::LtlContext* contractParser::FileContext::ltl(size_t i) {
  return getRuleContext<contractParser::LtlContext>(i);
}

std::vector<tree::TerminalNode *> contractParser::FileContext::NEWLINE() {
  return getTokens(contractParser::NEWLINE);
}

tree::TerminalNode* contractParser::FileContext::NEWLINE(size_t i) {
  return getToken(contractParser::NEWLINE, i);
}


size_t contractParser::FileContext::getRuleIndex() const {
  return contractParser::RuleFile;
}

void contractParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void contractParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

contractParser::FileContext* contractParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, contractParser::RuleFile);
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
    setState(15); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(12);
      ltl(0);
      setState(13);
      match(contractParser::NEWLINE);
      setState(17); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 386528) != 0));
    setState(19);
    match(contractParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LtlContext ------------------------------------------------------------------

contractParser::LtlContext::LtlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

contractParser::ProposContext* contractParser::LtlContext::propos() {
  return getRuleContext<contractParser::ProposContext>(0);
}

std::vector<contractParser::LtlContext *> contractParser::LtlContext::ltl() {
  return getRuleContexts<contractParser::LtlContext>();
}

contractParser::LtlContext* contractParser::LtlContext::ltl(size_t i) {
  return getRuleContext<contractParser::LtlContext>(i);
}


size_t contractParser::LtlContext::getRuleIndex() const {
  return contractParser::RuleLtl;
}

void contractParser::LtlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLtl(this);
}

void contractParser::LtlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLtl(this);
}


contractParser::LtlContext* contractParser::ltl() {
   return ltl(0);
}

contractParser::LtlContext* contractParser::ltl(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  contractParser::LtlContext *_localctx = _tracker.createInstance<LtlContext>(_ctx, parentState);
  contractParser::LtlContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, contractParser::RuleLtl, precedence);

    

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
    setState(35);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(22);
      propos(0);
      break;
    }

    case 2: {
      setState(23);
      match(contractParser::T__4);
      setState(24);
      ltl(6);
      break;
    }

    case 3: {
      setState(25);
      match(contractParser::T__5);
      setState(26);
      ltl(5);
      break;
    }

    case 4: {
      setState(27);
      match(contractParser::T__6);
      setState(28);
      ltl(4);
      break;
    }

    case 5: {
      setState(29);
      match(contractParser::T__7);
      setState(30);
      ltl(3);
      break;
    }

    case 6: {
      setState(31);
      match(contractParser::T__9);
      setState(32);
      ltl(0);
      setState(33);
      match(contractParser::T__10);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(54);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(52);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LtlContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLtl);
          setState(37);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(38);
          match(contractParser::T__0);
          setState(39);
          ltl(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LtlContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLtl);
          setState(40);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(41);
          match(contractParser::T__1);
          setState(42);
          ltl(10);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<LtlContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLtl);
          setState(43);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(44);
          match(contractParser::T__2);
          setState(45);
          ltl(9);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<LtlContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLtl);
          setState(46);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(47);
          match(contractParser::T__3);
          setState(48);
          ltl(8);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<LtlContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLtl);
          setState(49);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(50);
          match(contractParser::T__8);
          setState(51);
          ltl(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(56);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ProposContext ------------------------------------------------------------------

contractParser::ProposContext::ProposContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

contractParser::Atomic_proposContext* contractParser::ProposContext::atomic_propos() {
  return getRuleContext<contractParser::Atomic_proposContext>(0);
}

contractParser::QuanContext* contractParser::ProposContext::quan() {
  return getRuleContext<contractParser::QuanContext>(0);
}

tree::TerminalNode* contractParser::ProposContext::COLON() {
  return getToken(contractParser::COLON, 0);
}

std::vector<contractParser::ProposContext *> contractParser::ProposContext::propos() {
  return getRuleContexts<contractParser::ProposContext>();
}

contractParser::ProposContext* contractParser::ProposContext::propos(size_t i) {
  return getRuleContext<contractParser::ProposContext>(i);
}


size_t contractParser::ProposContext::getRuleIndex() const {
  return contractParser::RulePropos;
}

void contractParser::ProposContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropos(this);
}

void contractParser::ProposContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropos(this);
}


contractParser::ProposContext* contractParser::propos() {
   return propos(0);
}

contractParser::ProposContext* contractParser::propos(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  contractParser::ProposContext *_localctx = _tracker.createInstance<ProposContext>(_ctx, parentState);
  contractParser::ProposContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, contractParser::RulePropos, precedence);

    

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
    setState(67);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(58);
      atomic_propos();
      break;
    }

    case 2: {
      setState(59);
      quan();
      setState(60);
      match(contractParser::COLON);
      setState(61);
      propos(2);
      break;
    }

    case 3: {
      setState(63);
      match(contractParser::T__9);
      setState(64);
      propos(0);
      setState(65);
      match(contractParser::T__10);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(83);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(81);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ProposContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePropos);
          setState(69);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(70);
          match(contractParser::T__0);
          setState(71);
          propos(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ProposContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePropos);
          setState(72);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(73);
          match(contractParser::T__1);
          setState(74);
          propos(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ProposContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePropos);
          setState(75);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(76);
          match(contractParser::T__2);
          setState(77);
          propos(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ProposContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePropos);
          setState(78);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(79);
          match(contractParser::T__3);
          setState(80);
          propos(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(85);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Atomic_proposContext ------------------------------------------------------------------

contractParser::Atomic_proposContext::Atomic_proposContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<contractParser::ExprContext *> contractParser::Atomic_proposContext::expr() {
  return getRuleContexts<contractParser::ExprContext>();
}

contractParser::ExprContext* contractParser::Atomic_proposContext::expr(size_t i) {
  return getRuleContext<contractParser::ExprContext>(i);
}

tree::TerminalNode* contractParser::Atomic_proposContext::COMP() {
  return getToken(contractParser::COMP, 0);
}

contractParser::QuanContext* contractParser::Atomic_proposContext::quan() {
  return getRuleContext<contractParser::QuanContext>(0);
}

tree::TerminalNode* contractParser::Atomic_proposContext::COLON() {
  return getToken(contractParser::COLON, 0);
}

std::vector<contractParser::Atomic_proposContext *> contractParser::Atomic_proposContext::atomic_propos() {
  return getRuleContexts<contractParser::Atomic_proposContext>();
}

contractParser::Atomic_proposContext* contractParser::Atomic_proposContext::atomic_propos(size_t i) {
  return getRuleContext<contractParser::Atomic_proposContext>(i);
}

std::vector<tree::TerminalNode *> contractParser::Atomic_proposContext::LOP() {
  return getTokens(contractParser::LOP);
}

tree::TerminalNode* contractParser::Atomic_proposContext::LOP(size_t i) {
  return getToken(contractParser::LOP, i);
}


size_t contractParser::Atomic_proposContext::getRuleIndex() const {
  return contractParser::RuleAtomic_propos;
}

void contractParser::Atomic_proposContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomic_propos(this);
}

void contractParser::Atomic_proposContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomic_propos(this);
}

contractParser::Atomic_proposContext* contractParser::atomic_propos() {
  Atomic_proposContext *_localctx = _tracker.createInstance<Atomic_proposContext>(_ctx, getState());
  enterRule(_localctx, 6, contractParser::RuleAtomic_propos);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(105);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(86);
      expr(0);
      setState(87);
      antlrcpp::downCast<Atomic_proposContext *>(_localctx)->op = match(contractParser::COMP);
      setState(88);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(90);
      match(contractParser::T__9);
      setState(91);
      quan();
      setState(92);
      match(contractParser::COLON);
      setState(93);
      match(contractParser::T__9);
      setState(94);
      atomic_propos();
      setState(99);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == contractParser::LOP) {
        setState(95);
        match(contractParser::LOP);
        setState(96);
        atomic_propos();
        setState(101);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(102);
      match(contractParser::T__10);
      setState(103);
      match(contractParser::T__10);
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

//----------------- QuanContext ------------------------------------------------------------------

contractParser::QuanContext::QuanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> contractParser::QuanContext::QUAN() {
  return getTokens(contractParser::QUAN);
}

tree::TerminalNode* contractParser::QuanContext::QUAN(size_t i) {
  return getToken(contractParser::QUAN, i);
}

std::vector<tree::TerminalNode *> contractParser::QuanContext::VAR() {
  return getTokens(contractParser::VAR);
}

tree::TerminalNode* contractParser::QuanContext::VAR(size_t i) {
  return getToken(contractParser::VAR, i);
}

std::vector<tree::TerminalNode *> contractParser::QuanContext::COMMA() {
  return getTokens(contractParser::COMMA);
}

tree::TerminalNode* contractParser::QuanContext::COMMA(size_t i) {
  return getToken(contractParser::COMMA, i);
}

contractParser::QuanContext* contractParser::QuanContext::quan() {
  return getRuleContext<contractParser::QuanContext>(0);
}


size_t contractParser::QuanContext::getRuleIndex() const {
  return contractParser::RuleQuan;
}

void contractParser::QuanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuan(this);
}

void contractParser::QuanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuan(this);
}

contractParser::QuanContext* contractParser::quan() {
  QuanContext *_localctx = _tracker.createInstance<QuanContext>(_ctx, getState());
  enterRule(_localctx, 8, contractParser::RuleQuan);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case contractParser::QUAN: {
        enterOuterAlt(_localctx, 1);
        setState(118); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(107);
          match(contractParser::QUAN);
          setState(108);
          match(contractParser::T__9);
          setState(109);
          match(contractParser::VAR);
          setState(114);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == contractParser::COMMA) {
            setState(110);
            match(contractParser::COMMA);
            setState(111);
            match(contractParser::VAR);
            setState(116);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(117);
          match(contractParser::T__10);
          setState(120); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == contractParser::QUAN);
        break;
      }

      case contractParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(122);
        match(contractParser::T__9);
        setState(123);
        quan();
        setState(124);
        match(contractParser::T__10);
        break;
      }

    default:
      throw NoViableAltException(this);
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

contractParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<contractParser::ExprContext *> contractParser::ExprContext::expr() {
  return getRuleContexts<contractParser::ExprContext>();
}

contractParser::ExprContext* contractParser::ExprContext::expr(size_t i) {
  return getRuleContext<contractParser::ExprContext>(i);
}

tree::TerminalNode* contractParser::ExprContext::POW() {
  return getToken(contractParser::POW, 0);
}

tree::TerminalNode* contractParser::ExprContext::VAR() {
  return getToken(contractParser::VAR, 0);
}

std::vector<tree::TerminalNode *> contractParser::ExprContext::COMMA() {
  return getTokens(contractParser::COMMA);
}

tree::TerminalNode* contractParser::ExprContext::COMMA(size_t i) {
  return getToken(contractParser::COMMA, i);
}

tree::TerminalNode* contractParser::ExprContext::SUB() {
  return getToken(contractParser::SUB, 0);
}

tree::TerminalNode* contractParser::ExprContext::VALUE() {
  return getToken(contractParser::VALUE, 0);
}

tree::TerminalNode* contractParser::ExprContext::ARRAY() {
  return getToken(contractParser::ARRAY, 0);
}

tree::TerminalNode* contractParser::ExprContext::MUL() {
  return getToken(contractParser::MUL, 0);
}

tree::TerminalNode* contractParser::ExprContext::DIV() {
  return getToken(contractParser::DIV, 0);
}

tree::TerminalNode* contractParser::ExprContext::MOD() {
  return getToken(contractParser::MOD, 0);
}

tree::TerminalNode* contractParser::ExprContext::ADD() {
  return getToken(contractParser::ADD, 0);
}


size_t contractParser::ExprContext::getRuleIndex() const {
  return contractParser::RuleExpr;
}

void contractParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void contractParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


contractParser::ExprContext* contractParser::expr() {
   return expr(0);
}

contractParser::ExprContext* contractParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  contractParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  contractParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, contractParser::RuleExpr, precedence);

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
    setState(171);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(129);
      match(contractParser::T__9);
      setState(130);
      expr(0);
      setState(131);
      antlrcpp::downCast<ExprContext *>(_localctx)->op = match(contractParser::POW);
      setState(132);
      expr(0);
      setState(133);
      match(contractParser::T__10);
      break;
    }

    case 2: {
      setState(135);
      match(contractParser::VAR);
      setState(147); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(136);
                match(contractParser::T__9);
                setState(137);
                expr(0);
                setState(142);
                _errHandler->sync(this);
                _la = _input->LA(1);
                while (_la == contractParser::COMMA) {
                  setState(138);
                  match(contractParser::COMMA);
                  setState(139);
                  expr(0);
                  setState(144);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                }
                setState(145);
                match(contractParser::T__10);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(149); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 3: {
      setState(151);
      match(contractParser::T__9);
      setState(152);
      expr(0);
      setState(157);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == contractParser::COMMA) {
        setState(153);
        match(contractParser::COMMA);
        setState(154);
        expr(0);
        setState(159);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(160);
      match(contractParser::T__10);
      break;
    }

    case 4: {
      setState(162);
      match(contractParser::SUB);
      setState(163);
      match(contractParser::VALUE);
      break;
    }

    case 5: {
      setState(164);
      match(contractParser::VALUE);
      break;
    }

    case 6: {
      setState(165);
      match(contractParser::ARRAY);
      break;
    }

    case 7: {
      setState(166);
      match(contractParser::VAR);
      break;
    }

    case 8: {
      setState(167);
      match(contractParser::T__9);
      setState(168);
      expr(0);
      setState(169);
      match(contractParser::T__10);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(181);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(179);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(173);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(174);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 3670016) != 0))) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(175);
          expr(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(176);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(177);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == contractParser::ADD

          || _la == contractParser::SUB)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(178);
          expr(9);
          break;
        }

        default:
          break;
        } 
      }
      setState(183);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool contractParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return ltlSempred(antlrcpp::downCast<LtlContext *>(context), predicateIndex);
    case 2: return proposSempred(antlrcpp::downCast<ProposContext *>(context), predicateIndex);
    case 5: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool contractParser::ltlSempred(LtlContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool contractParser::proposSempred(ProposContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 5);
    case 7: return precpred(_ctx, 4);
    case 8: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool contractParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 9);
    case 10: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

void contractParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  contractParserInitialize();
#else
  ::antlr4::internal::call_once(contractParserOnceFlag, contractParserInitialize);
#endif
}
