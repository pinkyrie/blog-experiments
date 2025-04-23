cmake_minimum_required(VERSION 3.29)
project(cxxparallel101 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")
message(STATUS "compiler type: ${CMAKE_CXX_COMPILER_ID}")

# 直接链接
#add_executable(cpptest test.cpp func.cpp)


# 静态链接
# 生成静态库（libfunc.a）
add_library(func STATIC func.cpp)
# 生成可执行文件
add_executable(cpptest test.cpp)
# 静态链接 libfunc.a
target_link_libraries(cpptest PRIVATE func)


## 动态链接
## 创建共享库 mylib
#add_library(func SHARED func.cpp)
#target_include_directories(func PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})
## 创建可执行文件 myapp
#add_executable(cpptest test.cpp)
## 将 mylib 共享库链接到 myapp
#target_link_libraries(cpptest PRIVATE func)