cmake_minimum_required(VERSION 3.28)
project(fuzzer)

set(CMAKE_CXX_STANDARD 23)

add_executable(fuzzer main.cpp)
