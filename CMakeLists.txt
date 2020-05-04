cmake_minimum_required(VERSION 3.16)
project(littl C)

set(CMAKE_C_STANDARD 11)

add_executable(littl src/main.c src/lexer/lexer.c)