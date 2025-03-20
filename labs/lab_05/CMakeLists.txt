cmake_minimum_required(VERSION 3.29)
project(lab_05 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(lab_05 main.c
        sources/stack.c
        headers/stack.h
)

