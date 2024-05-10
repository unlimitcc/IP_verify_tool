cmake_minimum_required(VERSION 3.22)
project (VERI)

file(GLOB_RECURSE CPP_FILES ${PROJECT_SOURCE_DIR}/antlr4_propos/*.cpp ${PROJECT_SOURCE_DIR}/antlr4_cal/*.cpp)

set(ANTLR4_PROPOS ${PROJECT_SOURCE_DIR}/antlr4_propos)
set(ANTLR4_CAL ${PROJECT_SOURCE_DIR}/antlr4_cal)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${ANTLR4_PROPOS} ${ANTLR4_CAL})
add_executable(main main.cpp aux_fun.cpp ${CPP_FILES})
target_link_libraries(main antlr4-runtime)



