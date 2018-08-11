cmake_minimum_required(VERSION 3.8)
project(LinearListClass)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        LinearList.h
        LinkedList.h
        main.cpp
        SeqList.h)

add_executable(LinearListClass ${SOURCE_FILES})