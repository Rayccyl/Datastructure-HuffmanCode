cmake_minimum_required(VERSION 3.25)
project(HuffmanTreeLocal)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fexec-charset=GBK")
add_executable(HuffmanTreeLocal main.cpp I.cpp E.cpp D.cpp T.cpp P.cpp HuffmanCode.h)
