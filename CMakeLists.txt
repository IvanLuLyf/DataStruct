cmake_minimum_required(VERSION 3.8)
project(ThreadTreeClass)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ThreadTree.h)
add_executable(ThreadTreeClass ${SOURCE_FILES})