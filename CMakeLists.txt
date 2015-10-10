cmake_minimum_required(VERSION 3.3)
project(InverseMatrix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES InverseMatrix.cpp InverseMatrix.h MyTest.cpp MyTest.h main.cpp)
add_executable(InverseMatrix ${SOURCE_FILES})