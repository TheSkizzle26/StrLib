cmake_minimum_required(VERSION 4.2)
project(StrLib C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall)
add_executable(StrLib test.c)
