cmake_minimum_required(VERSION 2.4)

project(test_proj) 

add_executable(app
src/main.cpp 
)

set(EXECUTABLE_OUTPUT_PATH src)