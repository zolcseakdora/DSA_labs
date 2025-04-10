cmake_minimum_required(VERSION 3.30)
project(Gyak2 C)

set(CMAKE_C_STANDARD 23)
include_directories(headers)
add_executable(Gyak2 main.c
        sources/ball.c
        headers/ball.h)
