cmake_minimum_required(VERSION 3.8)
project(BinaryTreeClass)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BinaryTree.h)
add_executable(BinaryTreeClass ${SOURCE_FILES})