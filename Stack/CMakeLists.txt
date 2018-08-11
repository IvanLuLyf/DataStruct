cmake_minimum_required(VERSION 3.8)
project(StackClass)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Stack.h SeqStack.h LinkedStack.h Calculator.h)
add_executable(StackClass ${SOURCE_FILES})