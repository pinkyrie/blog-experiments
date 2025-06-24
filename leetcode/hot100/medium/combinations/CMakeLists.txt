cmake_minimum_required(VERSION 3.29)
project(cxxparallel101 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# 或者明确指定 MSVC 扩展
if (MSVC)
    add_compile_options(/std:c++latest)
endif()
add_executable(cpptest test.cpp)