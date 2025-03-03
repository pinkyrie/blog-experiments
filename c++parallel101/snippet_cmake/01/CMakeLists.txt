cmake_minimum_required(VERSION 3.29)
set(PROJECT_VERSION "1.0")
project(cxxparallel101 LANGUAGES CXX VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")

configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(cpptest test.cpp)
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
#target_include_directories(cpptest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/TutorialConfig.h)
target_include_directories(cpptest PUBLIC ${PROJECT_BINARY_DIR})

