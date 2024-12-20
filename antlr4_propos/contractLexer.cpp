
// Generated from contract.g4 by ANTLR 4.13.1


#include "contractLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ContractLexerStaticData final {
  ContractLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ContractLexerStaticData(const ContractLexerStaticData&) = delete;
  ContractLexerStaticData(ContractLexerStaticData&&) = delete;
  ContractLexerStaticData& operator=(const ContractLexerStaticData&) = delete;
  ContractLexerStaticData& operator=(ContractLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag contractlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ContractLexerStaticData *contractlexerLexerStaticData = nullptr;

void contractlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (contractlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(contractlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ContractLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "LOP", "QUAN", "INT", "VALUE", "VAR", "INDEX", "ARRAY", 
      "ADD", "SUB", "MUL", "DIV", "MOD", "POW", "LIMIT", "TILDE", "RANGE", 
      "COMP", "COLON", "COMMA", "POINT", "SKIP1", "NEWLINE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,28,220,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,
  	10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,3,11,99,8,11,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,112,8,12,1,13,1,13,5,13,116,8,
  	13,10,13,12,13,119,9,13,1,13,3,13,122,8,13,1,14,1,14,1,14,1,14,1,14,3,
  	14,129,8,14,1,15,1,15,5,15,133,8,15,10,15,12,15,136,9,15,1,16,1,16,4,
  	16,140,8,16,11,16,12,16,141,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,4,
  	17,152,8,17,11,17,12,17,153,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,
  	22,1,22,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,5,24,177,
  	8,24,10,24,12,24,180,9,24,1,24,1,24,3,24,184,8,24,1,25,1,25,1,26,1,26,
  	1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,201,8,27,
  	1,28,1,28,1,29,1,29,1,30,1,30,1,31,4,31,210,8,31,11,31,12,31,211,1,31,
  	1,31,1,32,3,32,217,8,32,1,32,1,32,0,0,33,1,1,3,2,5,3,7,4,9,5,11,6,13,
  	7,15,8,17,9,19,10,21,11,23,12,25,13,27,0,29,14,31,15,33,0,35,16,37,17,
  	39,18,41,19,43,20,45,21,47,22,49,0,51,0,53,23,55,24,57,25,59,26,61,0,
  	63,27,65,28,1,0,7,2,0,38,38,124,124,1,0,49,57,1,0,48,57,4,0,48,57,65,
  	90,95,95,97,122,5,0,46,46,48,57,65,90,95,95,97,122,3,0,48,57,65,90,97,
  	122,2,0,9,9,32,32,235,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,
  	0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,
  	1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,29,1,0,0,0,0,31,1,0,
  	0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,
  	0,45,1,0,0,0,0,47,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,
  	1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,1,67,1,0,0,0,3,69,1,0,0,0,5,71,1,0,
  	0,0,7,74,1,0,0,0,9,78,1,0,0,0,11,80,1,0,0,0,13,82,1,0,0,0,15,84,1,0,0,
  	0,17,86,1,0,0,0,19,88,1,0,0,0,21,90,1,0,0,0,23,98,1,0,0,0,25,111,1,0,
  	0,0,27,121,1,0,0,0,29,128,1,0,0,0,31,130,1,0,0,0,33,137,1,0,0,0,35,145,
  	1,0,0,0,37,155,1,0,0,0,39,157,1,0,0,0,41,159,1,0,0,0,43,161,1,0,0,0,45,
  	163,1,0,0,0,47,165,1,0,0,0,49,183,1,0,0,0,51,185,1,0,0,0,53,187,1,0,0,
  	0,55,200,1,0,0,0,57,202,1,0,0,0,59,204,1,0,0,0,61,206,1,0,0,0,63,209,
  	1,0,0,0,65,216,1,0,0,0,67,68,5,38,0,0,68,2,1,0,0,0,69,70,5,124,0,0,70,
  	4,1,0,0,0,71,72,5,45,0,0,72,73,5,62,0,0,73,6,1,0,0,0,74,75,5,60,0,0,75,
  	76,5,45,0,0,76,77,5,62,0,0,77,8,1,0,0,0,78,79,5,33,0,0,79,10,1,0,0,0,
  	80,81,5,88,0,0,81,12,1,0,0,0,82,83,5,71,0,0,83,14,1,0,0,0,84,85,5,70,
  	0,0,85,16,1,0,0,0,86,87,5,85,0,0,87,18,1,0,0,0,88,89,5,40,0,0,89,20,1,
  	0,0,0,90,91,5,41,0,0,91,22,1,0,0,0,92,99,7,0,0,0,93,94,5,45,0,0,94,99,
  	5,62,0,0,95,96,5,60,0,0,96,97,5,45,0,0,97,99,5,62,0,0,98,92,1,0,0,0,98,
  	93,1,0,0,0,98,95,1,0,0,0,99,24,1,0,0,0,100,101,5,69,0,0,101,102,5,88,
  	0,0,102,103,5,73,0,0,103,104,5,83,0,0,104,112,5,84,0,0,105,106,5,70,0,
  	0,106,107,5,79,0,0,107,108,5,82,0,0,108,109,5,65,0,0,109,110,5,76,0,0,
  	110,112,5,76,0,0,111,100,1,0,0,0,111,105,1,0,0,0,112,26,1,0,0,0,113,117,
  	7,1,0,0,114,116,7,2,0,0,115,114,1,0,0,0,116,119,1,0,0,0,117,115,1,0,0,
  	0,117,118,1,0,0,0,118,122,1,0,0,0,119,117,1,0,0,0,120,122,5,48,0,0,121,
  	113,1,0,0,0,121,120,1,0,0,0,122,28,1,0,0,0,123,129,3,27,13,0,124,125,
  	3,27,13,0,125,126,3,61,30,0,126,127,3,27,13,0,127,129,1,0,0,0,128,123,
  	1,0,0,0,128,124,1,0,0,0,129,30,1,0,0,0,130,134,7,3,0,0,131,133,7,4,0,
  	0,132,131,1,0,0,0,133,136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,
  	32,1,0,0,0,136,134,1,0,0,0,137,139,5,91,0,0,138,140,7,5,0,0,139,138,1,
  	0,0,0,140,141,1,0,0,0,141,139,1,0,0,0,141,142,1,0,0,0,142,143,1,0,0,0,
  	143,144,5,93,0,0,144,34,1,0,0,0,145,151,3,31,15,0,146,152,3,33,16,0,147,
  	148,5,91,0,0,148,149,3,35,17,0,149,150,5,93,0,0,150,152,1,0,0,0,151,146,
  	1,0,0,0,151,147,1,0,0,0,152,153,1,0,0,0,153,151,1,0,0,0,153,154,1,0,0,
  	0,154,36,1,0,0,0,155,156,5,43,0,0,156,38,1,0,0,0,157,158,5,45,0,0,158,
  	40,1,0,0,0,159,160,5,42,0,0,160,42,1,0,0,0,161,162,5,47,0,0,162,44,1,
  	0,0,0,163,164,5,37,0,0,164,46,1,0,0,0,165,166,5,94,0,0,166,48,1,0,0,0,
  	167,184,3,31,15,0,168,184,3,29,14,0,169,184,3,35,17,0,170,171,3,31,15,
  	0,171,172,5,40,0,0,172,178,3,49,24,0,173,174,3,59,29,0,174,175,3,49,24,
  	0,175,177,1,0,0,0,176,173,1,0,0,0,177,180,1,0,0,0,178,176,1,0,0,0,178,
  	179,1,0,0,0,179,181,1,0,0,0,180,178,1,0,0,0,181,182,5,41,0,0,182,184,
  	1,0,0,0,183,167,1,0,0,0,183,168,1,0,0,0,183,169,1,0,0,0,183,170,1,0,0,
  	0,184,50,1,0,0,0,185,186,5,126,0,0,186,52,1,0,0,0,187,188,3,49,24,0,188,
  	189,3,51,25,0,189,190,3,49,24,0,190,54,1,0,0,0,191,192,5,33,0,0,192,201,
  	5,61,0,0,193,201,5,62,0,0,194,195,5,62,0,0,195,201,5,61,0,0,196,201,5,
  	60,0,0,197,198,5,60,0,0,198,201,5,61,0,0,199,201,5,61,0,0,200,191,1,0,
  	0,0,200,193,1,0,0,0,200,194,1,0,0,0,200,196,1,0,0,0,200,197,1,0,0,0,200,
  	199,1,0,0,0,201,56,1,0,0,0,202,203,5,58,0,0,203,58,1,0,0,0,204,205,5,
  	44,0,0,205,60,1,0,0,0,206,207,5,46,0,0,207,62,1,0,0,0,208,210,7,6,0,0,
  	209,208,1,0,0,0,210,211,1,0,0,0,211,209,1,0,0,0,211,212,1,0,0,0,212,213,
  	1,0,0,0,213,214,6,31,0,0,214,64,1,0,0,0,215,217,5,114,0,0,216,215,1,0,
  	0,0,216,217,1,0,0,0,217,218,1,0,0,0,218,219,5,10,0,0,219,66,1,0,0,0,15,
  	0,98,111,117,121,128,134,141,151,153,178,183,200,211,216,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  contractlexerLexerStaticData = staticData.release();
}

}

contractLexer::contractLexer(CharStream *input) : Lexer(input) {
  contractLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *contractlexerLexerStaticData->atn, contractlexerLexerStaticData->decisionToDFA, contractlexerLexerStaticData->sharedContextCache);
}

contractLexer::~contractLexer() {
  delete _interpreter;
}

std::string contractLexer::getGrammarFileName() const {
  return "contract.g4";
}

const std::vector<std::string>& contractLexer::getRuleNames() const {
  return contractlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& contractLexer::getChannelNames() const {
  return contractlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& contractLexer::getModeNames() const {
  return contractlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& contractLexer::getVocabulary() const {
  return contractlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView contractLexer::getSerializedATN() const {
  return contractlexerLexerStaticData->serializedATN;
}

const atn::ATN& contractLexer::getATN() const {
  return *contractlexerLexerStaticData->atn;
}




void contractLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  contractlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(contractlexerLexerOnceFlag, contractlexerLexerInitialize);
#endif
}
