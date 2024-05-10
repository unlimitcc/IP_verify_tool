
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
      "T__0", "T__1", "ASS", "GUA", "LOP", "TOP", "QUAN", "VALUE", "VAR", 
      "INDEX", "ADD", "SUB", "MUL", "DIV", "MOD", "POW", "TILDE", "EDGE", 
      "RANGE", "COMP", "COLON", "COMMA", "POINT", "SKIP1", "SKIP2", "NEWLINE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "')'", "", "", "", "", "", "", "", "'+'", "'-'", "'*'", 
      "'/'", "'%'", "'^'", "", "", "':'", "','", "'.'"
    },
    std::vector<std::string>{
      "", "", "", "ASS", "GUA", "LOP", "TOP", "QUAN", "VALUE", "VAR", "ADD", 
      "SUB", "MUL", "DIV", "MOD", "POW", "RANGE", "COMP", "COLON", "COMMA", 
      "POINT", "SKIP1", "SKIP2", "NEWLINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,23,238,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,71,8,2,1,2,1,2,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,86,8,3,1,3,1,3,1,4,1,4,1,4,
  	3,4,93,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,3,5,110,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,123,8,6,
  	1,7,4,7,126,8,7,11,7,12,7,127,1,7,1,7,4,7,132,8,7,11,7,12,7,133,3,7,136,
  	8,7,1,7,1,7,1,7,3,7,141,8,7,1,8,4,8,144,8,8,11,8,12,8,145,1,8,1,8,1,8,
  	1,8,1,8,5,8,153,8,8,10,8,12,8,156,9,8,1,9,1,9,4,9,160,8,9,11,9,12,9,161,
  	1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,
  	16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,3,17,186,8,17,1,17,1,17,1,17,3,
  	17,191,8,17,5,17,193,8,17,10,17,12,17,196,9,17,1,17,1,17,3,17,200,8,17,
  	1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,
  	215,8,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,4,23,224,8,23,11,23,12,23,
  	225,1,23,1,23,1,24,1,24,1,24,1,24,1,25,3,25,235,8,25,1,25,1,25,0,0,26,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,0,21,10,23,11,25,12,27,13,
  	29,14,31,15,33,0,35,0,37,16,39,17,41,18,43,19,45,20,47,21,49,22,51,23,
  	1,0,5,2,0,38,38,124,124,1,0,48,57,4,0,48,57,65,90,95,95,97,122,3,0,48,
  	57,65,90,97,122,3,0,9,10,13,13,32,32,259,0,1,1,0,0,0,0,3,1,0,0,0,0,5,
  	1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,
  	0,0,17,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,
  	29,1,0,0,0,0,31,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,
  	0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,1,53,1,0,0,
  	0,3,55,1,0,0,0,5,57,1,0,0,0,7,74,1,0,0,0,9,92,1,0,0,0,11,109,1,0,0,0,
  	13,122,1,0,0,0,15,140,1,0,0,0,17,143,1,0,0,0,19,157,1,0,0,0,21,165,1,
  	0,0,0,23,167,1,0,0,0,25,169,1,0,0,0,27,171,1,0,0,0,29,173,1,0,0,0,31,
  	175,1,0,0,0,33,177,1,0,0,0,35,199,1,0,0,0,37,201,1,0,0,0,39,214,1,0,0,
  	0,41,216,1,0,0,0,43,218,1,0,0,0,45,220,1,0,0,0,47,223,1,0,0,0,49,229,
  	1,0,0,0,51,234,1,0,0,0,53,54,5,40,0,0,54,2,1,0,0,0,55,56,5,41,0,0,56,
  	4,1,0,0,0,57,58,5,65,0,0,58,59,5,115,0,0,59,60,5,115,0,0,60,61,5,117,
  	0,0,61,62,5,109,0,0,62,63,5,112,0,0,63,64,5,116,0,0,64,65,5,105,0,0,65,
  	66,5,111,0,0,66,67,5,110,0,0,67,68,5,115,0,0,68,70,1,0,0,0,69,71,3,15,
  	7,0,70,69,1,0,0,0,70,71,1,0,0,0,71,72,1,0,0,0,72,73,3,41,20,0,73,6,1,
  	0,0,0,74,75,5,71,0,0,75,76,5,117,0,0,76,77,5,97,0,0,77,78,5,114,0,0,78,
  	79,5,97,0,0,79,80,5,110,0,0,80,81,5,116,0,0,81,82,5,101,0,0,82,83,5,101,
  	0,0,83,85,1,0,0,0,84,86,3,15,7,0,85,84,1,0,0,0,85,86,1,0,0,0,86,87,1,
  	0,0,0,87,88,3,41,20,0,88,8,1,0,0,0,89,93,7,0,0,0,90,91,5,45,0,0,91,93,
  	5,62,0,0,92,89,1,0,0,0,92,90,1,0,0,0,93,10,1,0,0,0,94,95,5,70,0,0,95,
  	96,5,73,0,0,96,97,5,78,0,0,97,98,5,65,0,0,98,99,5,76,0,0,99,100,5,76,
  	0,0,100,110,5,89,0,0,101,102,5,71,0,0,102,103,5,76,0,0,103,104,5,79,0,
  	0,104,105,5,66,0,0,105,106,5,65,0,0,106,107,5,76,0,0,107,108,5,76,0,0,
  	108,110,5,89,0,0,109,94,1,0,0,0,109,101,1,0,0,0,110,12,1,0,0,0,111,112,
  	5,69,0,0,112,113,5,88,0,0,113,114,5,73,0,0,114,115,5,83,0,0,115,123,5,
  	84,0,0,116,117,5,70,0,0,117,118,5,79,0,0,118,119,5,82,0,0,119,120,5,65,
  	0,0,120,121,5,76,0,0,121,123,5,76,0,0,122,111,1,0,0,0,122,116,1,0,0,0,
  	123,14,1,0,0,0,124,126,7,1,0,0,125,124,1,0,0,0,126,127,1,0,0,0,127,125,
  	1,0,0,0,127,128,1,0,0,0,128,135,1,0,0,0,129,131,3,45,22,0,130,132,7,1,
  	0,0,131,130,1,0,0,0,132,133,1,0,0,0,133,131,1,0,0,0,133,134,1,0,0,0,134,
  	136,1,0,0,0,135,129,1,0,0,0,135,136,1,0,0,0,136,141,1,0,0,0,137,138,3,
  	23,11,0,138,139,3,15,7,0,139,141,1,0,0,0,140,125,1,0,0,0,140,137,1,0,
  	0,0,141,16,1,0,0,0,142,144,7,2,0,0,143,142,1,0,0,0,144,145,1,0,0,0,145,
  	143,1,0,0,0,145,146,1,0,0,0,146,154,1,0,0,0,147,153,3,19,9,0,148,149,
  	5,91,0,0,149,150,3,17,8,0,150,151,5,93,0,0,151,153,1,0,0,0,152,147,1,
  	0,0,0,152,148,1,0,0,0,153,156,1,0,0,0,154,152,1,0,0,0,154,155,1,0,0,0,
  	155,18,1,0,0,0,156,154,1,0,0,0,157,159,5,91,0,0,158,160,7,3,0,0,159,158,
  	1,0,0,0,160,161,1,0,0,0,161,159,1,0,0,0,161,162,1,0,0,0,162,163,1,0,0,
  	0,163,164,5,93,0,0,164,20,1,0,0,0,165,166,5,43,0,0,166,22,1,0,0,0,167,
  	168,5,45,0,0,168,24,1,0,0,0,169,170,5,42,0,0,170,26,1,0,0,0,171,172,5,
  	47,0,0,172,28,1,0,0,0,173,174,5,37,0,0,174,30,1,0,0,0,175,176,5,94,0,
  	0,176,32,1,0,0,0,177,178,5,126,0,0,178,34,1,0,0,0,179,200,3,15,7,0,180,
  	200,3,17,8,0,181,182,3,17,8,0,182,185,5,40,0,0,183,186,3,17,8,0,184,186,
  	3,15,7,0,185,183,1,0,0,0,185,184,1,0,0,0,186,194,1,0,0,0,187,190,3,43,
  	21,0,188,191,3,17,8,0,189,191,3,15,7,0,190,188,1,0,0,0,190,189,1,0,0,
  	0,191,193,1,0,0,0,192,187,1,0,0,0,193,196,1,0,0,0,194,192,1,0,0,0,194,
  	195,1,0,0,0,195,197,1,0,0,0,196,194,1,0,0,0,197,198,5,41,0,0,198,200,
  	1,0,0,0,199,179,1,0,0,0,199,180,1,0,0,0,199,181,1,0,0,0,200,36,1,0,0,
  	0,201,202,3,35,17,0,202,203,3,33,16,0,203,204,3,35,17,0,204,38,1,0,0,
  	0,205,206,5,33,0,0,206,215,5,61,0,0,207,215,5,62,0,0,208,209,5,62,0,0,
  	209,215,5,61,0,0,210,215,5,60,0,0,211,212,5,60,0,0,212,215,5,61,0,0,213,
  	215,5,61,0,0,214,205,1,0,0,0,214,207,1,0,0,0,214,208,1,0,0,0,214,210,
  	1,0,0,0,214,211,1,0,0,0,214,213,1,0,0,0,215,40,1,0,0,0,216,217,5,58,0,
  	0,217,42,1,0,0,0,218,219,5,44,0,0,219,44,1,0,0,0,220,221,5,46,0,0,221,
  	46,1,0,0,0,222,224,7,4,0,0,223,222,1,0,0,0,224,225,1,0,0,0,225,223,1,
  	0,0,0,225,226,1,0,0,0,226,227,1,0,0,0,227,228,6,23,0,0,228,48,1,0,0,0,
  	229,230,3,11,5,0,230,231,1,0,0,0,231,232,6,24,0,0,232,50,1,0,0,0,233,
  	235,5,114,0,0,234,233,1,0,0,0,234,235,1,0,0,0,235,236,1,0,0,0,236,237,
  	5,10,0,0,237,52,1,0,0,0,21,0,70,85,92,109,122,127,133,135,140,145,152,
  	154,161,185,190,194,199,214,225,234,1,6,0,0
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
