cmake_minimum_required(VERSION 3.30)
project(Gyak3 C)

set(CMAKE_C_STANDARD 23)
include_directories(headers)
add_executable(Gyak3 main.c
        sources/balls.c
        headers/balls.h)
