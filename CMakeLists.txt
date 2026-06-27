cmake_minimum_required(VERSION 4.2)
project(StrLib C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-O3 -Wall)
add_executable(StrLib re_test.c)
