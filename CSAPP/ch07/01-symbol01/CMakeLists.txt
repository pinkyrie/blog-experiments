cmake_minimum_required(VERSION 3.10)

# 项目名称
project(symbolTest)

# 指定编译器标准（可选）
set(CMAKE_C_STANDARD 11)

# 添加可执行文件
add_executable(symbolTest fool.c barl.c)
