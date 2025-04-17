cmake_minimum_required(VERSION 3.29)
project(cxxparallel101 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(test test.cpp
        stack2.hpp
)