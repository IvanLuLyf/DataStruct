cmake_minimum_required(VERSION 3.8)
project(QueueClass)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Queue.h SeqQueue.h LinkedQueue.h CircleLinkedQueue.h)
add_executable(QueueClass ${SOURCE_FILES})