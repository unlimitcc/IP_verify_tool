
// Generated from NC.g4 by ANTLR 4.13.1


#include "NCLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct NCLexerStaticData final {
  NCLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  NCLexerStaticData(const NCLexerStaticData&) = delete;
  NCLexerStaticData(NCLexerStaticData&&) = delete;
  NCLexerStaticData& operator=(const NCLexerStaticData&) = delete;
  NCLexerStaticData& operator=(NCLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag nclexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
NCLexerStaticData *nclexerLexerStaticData = nullptr;

void nclexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (nclexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(nclexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<NCLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "ID", "NUM", "NEWLINE", "WS", "MUL", "DIV", 
      "MOD", "ADD", "SUB", "POW"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,13,75,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,1,0,1,1,1,
  	1,1,2,1,2,1,3,4,3,35,8,3,11,3,12,3,36,1,4,4,4,40,8,4,11,4,12,4,41,1,4,
  	1,4,4,4,46,8,4,11,4,12,4,47,3,4,50,8,4,1,5,3,5,53,8,5,1,5,1,5,1,6,4,6,
  	58,8,6,11,6,12,6,59,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,
  	11,1,12,1,12,0,0,13,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,
  	11,23,12,25,13,1,0,3,2,0,65,90,97,122,1,0,48,57,2,0,9,9,32,32,80,0,1,
  	1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,
  	0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,
  	1,0,0,0,0,25,1,0,0,0,1,27,1,0,0,0,3,29,1,0,0,0,5,31,1,0,0,0,7,34,1,0,
  	0,0,9,39,1,0,0,0,11,52,1,0,0,0,13,57,1,0,0,0,15,63,1,0,0,0,17,65,1,0,
  	0,0,19,67,1,0,0,0,21,69,1,0,0,0,23,71,1,0,0,0,25,73,1,0,0,0,27,28,5,61,
  	0,0,28,2,1,0,0,0,29,30,5,40,0,0,30,4,1,0,0,0,31,32,5,41,0,0,32,6,1,0,
  	0,0,33,35,7,0,0,0,34,33,1,0,0,0,35,36,1,0,0,0,36,34,1,0,0,0,36,37,1,0,
  	0,0,37,8,1,0,0,0,38,40,7,1,0,0,39,38,1,0,0,0,40,41,1,0,0,0,41,39,1,0,
  	0,0,41,42,1,0,0,0,42,49,1,0,0,0,43,45,5,46,0,0,44,46,7,1,0,0,45,44,1,
  	0,0,0,46,47,1,0,0,0,47,45,1,0,0,0,47,48,1,0,0,0,48,50,1,0,0,0,49,43,1,
  	0,0,0,49,50,1,0,0,0,50,10,1,0,0,0,51,53,5,13,0,0,52,51,1,0,0,0,52,53,
  	1,0,0,0,53,54,1,0,0,0,54,55,5,10,0,0,55,12,1,0,0,0,56,58,7,2,0,0,57,56,
  	1,0,0,0,58,59,1,0,0,0,59,57,1,0,0,0,59,60,1,0,0,0,60,61,1,0,0,0,61,62,
  	6,6,0,0,62,14,1,0,0,0,63,64,5,42,0,0,64,16,1,0,0,0,65,66,5,47,0,0,66,
  	18,1,0,0,0,67,68,5,37,0,0,68,20,1,0,0,0,69,70,5,43,0,0,70,22,1,0,0,0,
  	71,72,5,45,0,0,72,24,1,0,0,0,73,74,5,94,0,0,74,26,1,0,0,0,7,0,36,41,47,
  	49,52,59,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  nclexerLexerStaticData = staticData.release();
}

}

NCLexer::NCLexer(CharStream *input) : Lexer(input) {
  NCLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *nclexerLexerStaticData->atn, nclexerLexerStaticData->decisionToDFA, nclexerLexerStaticData->sharedContextCache);
}

NCLexer::~NCLexer() {
  delete _interpreter;
}

std::string NCLexer::getGrammarFileName() const {
  return "NC.g4";
}

const std::vector<std::string>& NCLexer::getRuleNames() const {
  return nclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& NCLexer::getChannelNames() const {
  return nclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& NCLexer::getModeNames() const {
  return nclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& NCLexer::getVocabulary() const {
  return nclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView NCLexer::getSerializedATN() const {
  return nclexerLexerStaticData->serializedATN;
}

const atn::ATN& NCLexer::getATN() const {
  return *nclexerLexerStaticData->atn;
}




void NCLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  nclexerLexerInitialize();
#else
  ::antlr4::internal::call_once(nclexerLexerOnceFlag, nclexerLexerInitialize);
#endif
}
