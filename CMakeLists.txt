cmake_minimum_required(VERSION 3.8)
project(HuffmanClass)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MinHeap.h HuffmanTree.h)
add_executable(HuffmanClass ${SOURCE_FILES})