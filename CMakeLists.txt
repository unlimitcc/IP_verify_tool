cmake_minimum_required(VERSION 3.16)
project (VERI)

file(GLOB_RECURSE CPP_FILES ${PROJECT_SOURCE_DIR}/antlr4_propos/*.cpp ${PROJECT_SOURCE_DIR}/antlr4_cal/*.cpp call_trace4cps.cpp Extract_Propos.cpp)

set(ANTLR4_PROPOS ${PROJECT_SOURCE_DIR}/antlr4_propos)
set(ANTLR4_CAL ${PROJECT_SOURCE_DIR}/antlr4_cal)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
set(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(IP_INCLUDE_PATH ${PARENT_DIR}/VeriHar-main/include)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${ANTLR4_PROPOS} ${ANTLR4_CAL})
add_executable(main main.cpp aux_fun.cpp ${CPP_FILES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${ANTLR4_PROPOS} ${ANTLR4_CAL})
add_executable(test test.cc aux_fun.cpp ${CPP_FILES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${ANTLR4_PROPOS} ${ANTLR4_CAL})
add_executable(test_time test_time.cpp aux_fun.cpp ${CPP_FILES})
target_link_libraries(main antlr4-runtime pthread)
target_link_libraries(test antlr4-runtime pthread)
target_link_libraries(test_time antlr4-runtime pthread)



