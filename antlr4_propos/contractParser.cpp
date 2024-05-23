
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
      "file", "init", "stat", "cond", "propos", "com", "quan", "expr"
    },
    std::vector<std::string>{
      "", "'('", "')'", "", "", "", "", "", "", "", "'+'", "'-'", "'*'", 
      "'/'", "'%'", "'^'", "", "", "':'", "','"
    },
    std::vector<std::string>{
      "", "", "", "ASS", "GUA", "LOP", "TOP", "QUAN", "VALUE", "VAR", "ADD", 
      "SUB", "MUL", "DIV", "MOD", "POW", "RANGE", "COMP", "COLON", "COMMA", 
      "SKIP1", "SKIP2", "NEWLINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,22,237,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,1,0,1,0,3,0,19,8,0,1,0,1,0,4,0,23,8,0,11,0,12,0,24,1,0,1,0,1,1,
  	1,1,1,1,1,1,5,1,33,8,1,10,1,12,1,36,9,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,44,
  	8,1,11,1,12,1,45,1,1,1,1,1,1,3,1,51,8,1,1,2,1,2,1,2,1,2,5,2,57,8,2,10,
  	2,12,2,60,9,2,1,2,1,2,1,2,1,2,1,2,1,2,4,2,68,8,2,11,2,12,2,69,1,2,1,2,
  	1,2,3,2,75,8,2,1,3,4,3,78,8,3,11,3,12,3,79,1,3,3,3,83,8,3,1,3,1,3,1,3,
  	1,3,5,3,89,8,3,10,3,12,3,92,9,3,1,3,1,3,1,3,1,3,5,3,98,8,3,10,3,12,3,
  	101,9,3,1,3,1,3,5,3,105,8,3,10,3,12,3,108,9,3,1,3,3,3,111,8,3,1,3,3,3,
  	114,8,3,1,3,3,3,117,8,3,1,4,4,4,120,8,4,11,4,12,4,121,1,4,3,4,125,8,4,
  	1,4,1,4,1,4,1,4,5,4,131,8,4,10,4,12,4,134,9,4,1,4,1,4,1,4,1,4,5,4,140,
  	8,4,10,4,12,4,143,9,4,1,4,1,4,5,4,147,8,4,10,4,12,4,150,9,4,1,4,3,4,153,
  	8,4,1,4,3,4,156,8,4,1,4,3,4,159,8,4,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,176,8,6,10,6,12,6,179,9,6,1,6,3,6,182,8,
  	6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,4,7,197,8,7,11,
  	7,12,7,198,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,5,7,211,8,7,10,7,12,
  	7,214,9,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,224,8,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,5,7,232,8,7,10,7,12,7,235,9,7,1,7,0,1,14,8,0,2,4,6,8,10,12,14,
  	0,2,1,0,12,14,1,0,10,11,266,0,18,1,0,0,0,2,50,1,0,0,0,4,74,1,0,0,0,6,
  	116,1,0,0,0,8,158,1,0,0,0,10,160,1,0,0,0,12,181,1,0,0,0,14,223,1,0,0,
  	0,16,17,5,3,0,0,17,19,3,2,1,0,18,16,1,0,0,0,18,19,1,0,0,0,19,22,1,0,0,
  	0,20,21,5,4,0,0,21,23,3,4,2,0,22,20,1,0,0,0,23,24,1,0,0,0,24,22,1,0,0,
  	0,24,25,1,0,0,0,25,26,1,0,0,0,26,27,5,0,0,1,27,1,1,0,0,0,28,29,5,1,0,
  	0,29,34,3,2,1,0,30,31,5,5,0,0,31,33,3,2,1,0,32,30,1,0,0,0,33,36,1,0,0,
  	0,34,32,1,0,0,0,34,35,1,0,0,0,35,37,1,0,0,0,36,34,1,0,0,0,37,38,5,2,0,
  	0,38,51,1,0,0,0,39,40,5,1,0,0,40,43,3,6,3,0,41,42,5,5,0,0,42,44,3,6,3,
  	0,43,41,1,0,0,0,44,45,1,0,0,0,45,43,1,0,0,0,45,46,1,0,0,0,46,47,1,0,0,
  	0,47,48,5,2,0,0,48,51,1,0,0,0,49,51,3,6,3,0,50,28,1,0,0,0,50,39,1,0,0,
  	0,50,49,1,0,0,0,51,3,1,0,0,0,52,53,5,1,0,0,53,58,3,4,2,0,54,55,5,5,0,
  	0,55,57,3,4,2,0,56,54,1,0,0,0,57,60,1,0,0,0,58,56,1,0,0,0,58,59,1,0,0,
  	0,59,61,1,0,0,0,60,58,1,0,0,0,61,62,5,2,0,0,62,75,1,0,0,0,63,64,5,1,0,
  	0,64,67,3,8,4,0,65,66,5,5,0,0,66,68,3,8,4,0,67,65,1,0,0,0,68,69,1,0,0,
  	0,69,67,1,0,0,0,69,70,1,0,0,0,70,71,1,0,0,0,71,72,5,2,0,0,72,75,1,0,0,
  	0,73,75,3,8,4,0,74,52,1,0,0,0,74,63,1,0,0,0,74,73,1,0,0,0,75,5,1,0,0,
  	0,76,78,3,12,6,0,77,76,1,0,0,0,78,79,1,0,0,0,79,77,1,0,0,0,79,80,1,0,
  	0,0,80,82,1,0,0,0,81,83,5,1,0,0,82,81,1,0,0,0,82,83,1,0,0,0,83,84,1,0,
  	0,0,84,85,5,1,0,0,85,90,3,10,5,0,86,87,5,5,0,0,87,89,3,10,5,0,88,86,1,
  	0,0,0,89,92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,93,1,0,0,0,92,90,1,
  	0,0,0,93,110,5,2,0,0,94,95,5,5,0,0,95,99,5,1,0,0,96,98,3,10,5,0,97,96,
  	1,0,0,0,98,101,1,0,0,0,99,97,1,0,0,0,99,100,1,0,0,0,100,106,1,0,0,0,101,
  	99,1,0,0,0,102,103,5,5,0,0,103,105,3,10,5,0,104,102,1,0,0,0,105,108,1,
  	0,0,0,106,104,1,0,0,0,106,107,1,0,0,0,107,109,1,0,0,0,108,106,1,0,0,0,
  	109,111,5,2,0,0,110,94,1,0,0,0,110,111,1,0,0,0,111,113,1,0,0,0,112,114,
  	5,2,0,0,113,112,1,0,0,0,113,114,1,0,0,0,114,117,1,0,0,0,115,117,3,10,
  	5,0,116,77,1,0,0,0,116,115,1,0,0,0,117,7,1,0,0,0,118,120,3,12,6,0,119,
  	118,1,0,0,0,120,121,1,0,0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,124,1,
  	0,0,0,123,125,5,1,0,0,124,123,1,0,0,0,124,125,1,0,0,0,125,126,1,0,0,0,
  	126,127,5,1,0,0,127,132,3,10,5,0,128,129,5,5,0,0,129,131,3,10,5,0,130,
  	128,1,0,0,0,131,134,1,0,0,0,132,130,1,0,0,0,132,133,1,0,0,0,133,135,1,
  	0,0,0,134,132,1,0,0,0,135,152,5,2,0,0,136,137,5,5,0,0,137,141,5,1,0,0,
  	138,140,3,10,5,0,139,138,1,0,0,0,140,143,1,0,0,0,141,139,1,0,0,0,141,
  	142,1,0,0,0,142,148,1,0,0,0,143,141,1,0,0,0,144,145,5,5,0,0,145,147,3,
  	10,5,0,146,144,1,0,0,0,147,150,1,0,0,0,148,146,1,0,0,0,148,149,1,0,0,
  	0,149,151,1,0,0,0,150,148,1,0,0,0,151,153,5,2,0,0,152,136,1,0,0,0,152,
  	153,1,0,0,0,153,155,1,0,0,0,154,156,5,2,0,0,155,154,1,0,0,0,155,156,1,
  	0,0,0,156,159,1,0,0,0,157,159,3,10,5,0,158,119,1,0,0,0,158,157,1,0,0,
  	0,159,9,1,0,0,0,160,161,3,14,7,0,161,162,5,17,0,0,162,163,3,14,7,0,163,
  	11,1,0,0,0,164,165,5,7,0,0,165,166,5,1,0,0,166,167,5,9,0,0,167,168,5,
  	18,0,0,168,169,5,16,0,0,169,182,5,2,0,0,170,171,5,7,0,0,171,172,5,1,0,
  	0,172,177,5,9,0,0,173,174,5,19,0,0,174,176,5,9,0,0,175,173,1,0,0,0,176,
  	179,1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,180,1,0,0,0,179,177,1,
  	0,0,0,180,182,5,2,0,0,181,164,1,0,0,0,181,170,1,0,0,0,182,13,1,0,0,0,
  	183,184,6,7,-1,0,184,185,5,1,0,0,185,186,3,14,7,0,186,187,5,15,0,0,187,
  	188,3,14,7,0,188,189,5,2,0,0,189,224,1,0,0,0,190,196,5,9,0,0,191,192,
  	5,1,0,0,192,193,5,9,0,0,193,194,5,18,0,0,194,195,5,16,0,0,195,197,5,2,
  	0,0,196,191,1,0,0,0,197,198,1,0,0,0,198,196,1,0,0,0,198,199,1,0,0,0,199,
  	200,1,0,0,0,200,201,5,1,0,0,201,202,3,14,7,0,202,203,5,2,0,0,203,224,
  	1,0,0,0,204,205,5,9,0,0,205,224,3,14,7,0,206,207,5,1,0,0,207,212,3,14,
  	7,0,208,209,5,19,0,0,209,211,3,14,7,0,210,208,1,0,0,0,211,214,1,0,0,0,
  	212,210,1,0,0,0,212,213,1,0,0,0,213,215,1,0,0,0,214,212,1,0,0,0,215,216,
  	5,2,0,0,216,224,1,0,0,0,217,224,5,8,0,0,218,224,5,9,0,0,219,220,5,1,0,
  	0,220,221,3,14,7,0,221,222,5,2,0,0,222,224,1,0,0,0,223,183,1,0,0,0,223,
  	190,1,0,0,0,223,204,1,0,0,0,223,206,1,0,0,0,223,217,1,0,0,0,223,218,1,
  	0,0,0,223,219,1,0,0,0,224,233,1,0,0,0,225,226,10,8,0,0,226,227,7,0,0,
  	0,227,232,3,14,7,9,228,229,10,7,0,0,229,230,7,1,0,0,230,232,3,14,7,8,
  	231,225,1,0,0,0,231,228,1,0,0,0,232,235,1,0,0,0,233,231,1,0,0,0,233,234,
  	1,0,0,0,234,15,1,0,0,0,235,233,1,0,0,0,31,18,24,34,45,50,58,69,74,79,
  	82,90,99,106,110,113,116,121,124,132,141,148,152,155,158,177,181,198,
  	212,223,231,233
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

tree::TerminalNode* contractParser::FileContext::ASS() {
  return getToken(contractParser::ASS, 0);
}

contractParser::InitContext* contractParser::FileContext::init() {
  return getRuleContext<contractParser::InitContext>(0);
}

std::vector<tree::TerminalNode *> contractParser::FileContext::GUA() {
  return getTokens(contractParser::GUA);
}

tree::TerminalNode* contractParser::FileContext::GUA(size_t i) {
  return getToken(contractParser::GUA, i);
}

std::vector<contractParser::StatContext *> contractParser::FileContext::stat() {
  return getRuleContexts<contractParser::StatContext>();
}

contractParser::StatContext* contractParser::FileContext::stat(size_t i) {
  return getRuleContext<contractParser::StatContext>(i);
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
    setState(18);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == contractParser::ASS) {
      setState(16);
      match(contractParser::ASS);
      setState(17);
      init();
    }
    setState(22); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(20);
      match(contractParser::GUA);
      setState(21);
      stat();
      setState(24); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == contractParser::GUA);
    setState(26);
    match(contractParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitContext ------------------------------------------------------------------

contractParser::InitContext::InitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<contractParser::InitContext *> contractParser::InitContext::init() {
  return getRuleContexts<contractParser::InitContext>();
}

contractParser::InitContext* contractParser::InitContext::init(size_t i) {
  return getRuleContext<contractParser::InitContext>(i);
}

std::vector<tree::TerminalNode *> contractParser::InitContext::LOP() {
  return getTokens(contractParser::LOP);
}

tree::TerminalNode* contractParser::InitContext::LOP(size_t i) {
  return getToken(contractParser::LOP, i);
}

std::vector<contractParser::CondContext *> contractParser::InitContext::cond() {
  return getRuleContexts<contractParser::CondContext>();
}

contractParser::CondContext* contractParser::InitContext::cond(size_t i) {
  return getRuleContext<contractParser::CondContext>(i);
}


size_t contractParser::InitContext::getRuleIndex() const {
  return contractParser::RuleInit;
}

void contractParser::InitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInit(this);
}

void contractParser::InitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInit(this);
}

contractParser::InitContext* contractParser::init() {
  InitContext *_localctx = _tracker.createInstance<InitContext>(_ctx, getState());
  enterRule(_localctx, 2, contractParser::RuleInit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(28);
      match(contractParser::T__0);
      setState(29);
      init();
      setState(34);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == contractParser::LOP) {
        setState(30);
        match(contractParser::LOP);
        setState(31);
        init();
        setState(36);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(37);
      match(contractParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(39);
      match(contractParser::T__0);
      setState(40);
      cond();
      setState(43); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(41);
        match(contractParser::LOP);
        setState(42);
        cond();
        setState(45); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == contractParser::LOP);
      setState(47);
      match(contractParser::T__1);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(49);
      cond();
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

//----------------- StatContext ------------------------------------------------------------------

contractParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<contractParser::StatContext *> contractParser::StatContext::stat() {
  return getRuleContexts<contractParser::StatContext>();
}

contractParser::StatContext* contractParser::StatContext::stat(size_t i) {
  return getRuleContext<contractParser::StatContext>(i);
}

std::vector<tree::TerminalNode *> contractParser::StatContext::LOP() {
  return getTokens(contractParser::LOP);
}

tree::TerminalNode* contractParser::StatContext::LOP(size_t i) {
  return getToken(contractParser::LOP, i);
}

std::vector<contractParser::ProposContext *> contractParser::StatContext::propos() {
  return getRuleContexts<contractParser::ProposContext>();
}

contractParser::ProposContext* contractParser::StatContext::propos(size_t i) {
  return getRuleContext<contractParser::ProposContext>(i);
}


size_t contractParser::StatContext::getRuleIndex() const {
  return contractParser::RuleStat;
}

void contractParser::StatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat(this);
}

void contractParser::StatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat(this);
}

contractParser::StatContext* contractParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 4, contractParser::RuleStat);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(74);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(52);
      match(contractParser::T__0);
      setState(53);
      stat();
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == contractParser::LOP) {
        setState(54);
        match(contractParser::LOP);
        setState(55);
        stat();
        setState(60);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(61);
      match(contractParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(63);
      match(contractParser::T__0);
      setState(64);
      propos();
      setState(67); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(65);
        match(contractParser::LOP);
        setState(66);
        propos();
        setState(69); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == contractParser::LOP);
      setState(71);
      match(contractParser::T__1);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(73);
      propos();
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

//----------------- CondContext ------------------------------------------------------------------

contractParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<contractParser::ComContext *> contractParser::CondContext::com() {
  return getRuleContexts<contractParser::ComContext>();
}

contractParser::ComContext* contractParser::CondContext::com(size_t i) {
  return getRuleContext<contractParser::ComContext>(i);
}

std::vector<contractParser::QuanContext *> contractParser::CondContext::quan() {
  return getRuleContexts<contractParser::QuanContext>();
}

contractParser::QuanContext* contractParser::CondContext::quan(size_t i) {
  return getRuleContext<contractParser::QuanContext>(i);
}

std::vector<tree::TerminalNode *> contractParser::CondContext::LOP() {
  return getTokens(contractParser::LOP);
}

tree::TerminalNode* contractParser::CondContext::LOP(size_t i) {
  return getToken(contractParser::LOP, i);
}


size_t contractParser::CondContext::getRuleIndex() const {
  return contractParser::RuleCond;
}

void contractParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void contractParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}

contractParser::CondContext* contractParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 6, contractParser::RuleCond);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(116);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case contractParser::QUAN: {
        enterOuterAlt(_localctx, 1);
        setState(77); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(76);
          quan();
          setState(79); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == contractParser::QUAN);
        setState(82);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          setState(81);
          match(contractParser::T__0);
          break;
        }

        default:
          break;
        }
        setState(84);
        match(contractParser::T__0);
        setState(85);
        com();
        setState(90);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == contractParser::LOP) {
          setState(86);
          match(contractParser::LOP);
          setState(87);
          com();
          setState(92);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(93);
        match(contractParser::T__1);
        setState(110);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          setState(94);
          match(contractParser::LOP);
          setState(95);
          match(contractParser::T__0);
          setState(99);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 770) != 0)) {
            setState(96);
            com();
            setState(101);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(106);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == contractParser::LOP) {
            setState(102);
            match(contractParser::LOP);
            setState(103);
            com();
            setState(108);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(109);
          match(contractParser::T__1);
          break;
        }

        default:
          break;
        }
        setState(113);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          setState(112);
          match(contractParser::T__1);
          break;
        }

        default:
          break;
        }
        break;
      }

      case contractParser::T__0:
      case contractParser::VALUE:
      case contractParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(115);
        com();
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

//----------------- ProposContext ------------------------------------------------------------------

contractParser::ProposContext::ProposContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<contractParser::ComContext *> contractParser::ProposContext::com() {
  return getRuleContexts<contractParser::ComContext>();
}

contractParser::ComContext* contractParser::ProposContext::com(size_t i) {
  return getRuleContext<contractParser::ComContext>(i);
}

std::vector<contractParser::QuanContext *> contractParser::ProposContext::quan() {
  return getRuleContexts<contractParser::QuanContext>();
}

contractParser::QuanContext* contractParser::ProposContext::quan(size_t i) {
  return getRuleContext<contractParser::QuanContext>(i);
}

std::vector<tree::TerminalNode *> contractParser::ProposContext::LOP() {
  return getTokens(contractParser::LOP);
}

tree::TerminalNode* contractParser::ProposContext::LOP(size_t i) {
  return getToken(contractParser::LOP, i);
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
  ProposContext *_localctx = _tracker.createInstance<ProposContext>(_ctx, getState());
  enterRule(_localctx, 8, contractParser::RulePropos);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case contractParser::QUAN: {
        enterOuterAlt(_localctx, 1);
        setState(119); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(118);
          quan();
          setState(121); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == contractParser::QUAN);
        setState(124);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          setState(123);
          match(contractParser::T__0);
          break;
        }

        default:
          break;
        }
        setState(126);
        match(contractParser::T__0);
        setState(127);
        com();
        setState(132);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == contractParser::LOP) {
          setState(128);
          match(contractParser::LOP);
          setState(129);
          com();
          setState(134);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(135);
        match(contractParser::T__1);
        setState(152);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          setState(136);
          match(contractParser::LOP);
          setState(137);
          match(contractParser::T__0);
          setState(141);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 770) != 0)) {
            setState(138);
            com();
            setState(143);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(148);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == contractParser::LOP) {
            setState(144);
            match(contractParser::LOP);
            setState(145);
            com();
            setState(150);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(151);
          match(contractParser::T__1);
          break;
        }

        default:
          break;
        }
        setState(155);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          setState(154);
          match(contractParser::T__1);
          break;
        }

        default:
          break;
        }
        break;
      }

      case contractParser::T__0:
      case contractParser::VALUE:
      case contractParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(157);
        com();
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

//----------------- ComContext ------------------------------------------------------------------

contractParser::ComContext::ComContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<contractParser::ExprContext *> contractParser::ComContext::expr() {
  return getRuleContexts<contractParser::ExprContext>();
}

contractParser::ExprContext* contractParser::ComContext::expr(size_t i) {
  return getRuleContext<contractParser::ExprContext>(i);
}

tree::TerminalNode* contractParser::ComContext::COMP() {
  return getToken(contractParser::COMP, 0);
}


size_t contractParser::ComContext::getRuleIndex() const {
  return contractParser::RuleCom;
}

void contractParser::ComContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCom(this);
}

void contractParser::ComContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<contractListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCom(this);
}

contractParser::ComContext* contractParser::com() {
  ComContext *_localctx = _tracker.createInstance<ComContext>(_ctx, getState());
  enterRule(_localctx, 10, contractParser::RuleCom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    expr(0);
    setState(161);
    antlrcpp::downCast<ComContext *>(_localctx)->op = match(contractParser::COMP);
    setState(162);
    expr(0);
   
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

tree::TerminalNode* contractParser::QuanContext::QUAN() {
  return getToken(contractParser::QUAN, 0);
}

std::vector<tree::TerminalNode *> contractParser::QuanContext::VAR() {
  return getTokens(contractParser::VAR);
}

tree::TerminalNode* contractParser::QuanContext::VAR(size_t i) {
  return getToken(contractParser::VAR, i);
}

tree::TerminalNode* contractParser::QuanContext::COLON() {
  return getToken(contractParser::COLON, 0);
}

tree::TerminalNode* contractParser::QuanContext::RANGE() {
  return getToken(contractParser::RANGE, 0);
}

std::vector<tree::TerminalNode *> contractParser::QuanContext::COMMA() {
  return getTokens(contractParser::COMMA);
}

tree::TerminalNode* contractParser::QuanContext::COMMA(size_t i) {
  return getToken(contractParser::COMMA, i);
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
  enterRule(_localctx, 12, contractParser::RuleQuan);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(164);
      match(contractParser::QUAN);
      setState(165);
      match(contractParser::T__0);
      setState(166);
      match(contractParser::VAR);
      setState(167);
      match(contractParser::COLON);
      setState(168);
      match(contractParser::RANGE);
      setState(169);
      match(contractParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(170);
      match(contractParser::QUAN);
      setState(171);
      match(contractParser::T__0);
      setState(172);
      match(contractParser::VAR);
      setState(177);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == contractParser::COMMA) {
        setState(173);
        match(contractParser::COMMA);
        setState(174);
        match(contractParser::VAR);
        setState(179);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(180);
      match(contractParser::T__1);
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

std::vector<tree::TerminalNode *> contractParser::ExprContext::VAR() {
  return getTokens(contractParser::VAR);
}

tree::TerminalNode* contractParser::ExprContext::VAR(size_t i) {
  return getToken(contractParser::VAR, i);
}

std::vector<tree::TerminalNode *> contractParser::ExprContext::COLON() {
  return getTokens(contractParser::COLON);
}

tree::TerminalNode* contractParser::ExprContext::COLON(size_t i) {
  return getToken(contractParser::COLON, i);
}

std::vector<tree::TerminalNode *> contractParser::ExprContext::RANGE() {
  return getTokens(contractParser::RANGE);
}

tree::TerminalNode* contractParser::ExprContext::RANGE(size_t i) {
  return getToken(contractParser::RANGE, i);
}

std::vector<tree::TerminalNode *> contractParser::ExprContext::COMMA() {
  return getTokens(contractParser::COMMA);
}

tree::TerminalNode* contractParser::ExprContext::COMMA(size_t i) {
  return getToken(contractParser::COMMA, i);
}

tree::TerminalNode* contractParser::ExprContext::VALUE() {
  return getToken(contractParser::VALUE, 0);
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

tree::TerminalNode* contractParser::ExprContext::SUB() {
  return getToken(contractParser::SUB, 0);
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
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, contractParser::RuleExpr, precedence);

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
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(184);
      match(contractParser::T__0);
      setState(185);
      expr(0);
      setState(186);
      antlrcpp::downCast<ExprContext *>(_localctx)->op = match(contractParser::POW);
      setState(187);
      expr(0);
      setState(188);
      match(contractParser::T__1);
      break;
    }

    case 2: {
      setState(190);
      match(contractParser::VAR);
      setState(196); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(191);
                match(contractParser::T__0);
                setState(192);
                match(contractParser::VAR);
                setState(193);
                match(contractParser::COLON);
                setState(194);
                match(contractParser::RANGE);
                setState(195);
                match(contractParser::T__1);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(198); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(200);
      match(contractParser::T__0);
      setState(201);
      expr(0);
      setState(202);
      match(contractParser::T__1);
      break;
    }

    case 3: {
      setState(204);
      match(contractParser::VAR);
      setState(205);
      expr(0);
      break;
    }

    case 4: {
      setState(206);
      match(contractParser::T__0);
      setState(207);
      expr(0);
      setState(212);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == contractParser::COMMA) {
        setState(208);
        match(contractParser::COMMA);
        setState(209);
        expr(0);
        setState(214);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(215);
      match(contractParser::T__1);
      break;
    }

    case 5: {
      setState(217);
      match(contractParser::VALUE);
      break;
    }

    case 6: {
      setState(218);
      match(contractParser::VAR);
      break;
    }

    case 7: {
      setState(219);
      match(contractParser::T__0);
      setState(220);
      expr(0);
      setState(221);
      match(contractParser::T__1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(233);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(231);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(225);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(226);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 28672) != 0))) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(227);
          expr(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(228);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(229);
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
          setState(230);
          expr(8);
          break;
        }

        default:
          break;
        } 
      }
      setState(235);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
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
    case 7: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool contractParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);

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
