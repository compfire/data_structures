# cmake_minimum_required(VERSION <specify CMake version here>)
project(complook)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Heap.cpp Heap.h BstNode.cpp BstNode.h)
add_executable(complook ${SOURCE_FILES})