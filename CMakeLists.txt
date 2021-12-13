cmake_minimum_required(VERSION 2.4)

project(test_proj) 

add_executable(app
src/main.cpp
src/lib/lexer.cpp 
src/lib/syntaxToken.cpp
)

set(EXECUTABLE_OUTPUT_PATH src)