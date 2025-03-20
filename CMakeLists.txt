cmake_minimum_required(VERSION 3.30)
project(interpreter C)

set(CMAKE_C_STANDARD 99)

add_executable(interpreter main.c
        token.h
        lexer.h
        lexer.c
        token.c
)
