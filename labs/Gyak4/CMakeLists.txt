cmake_minimum_required(VERSION 3.30)
project(Gyak4 C)

set(CMAKE_C_STANDARD 23)
include_directories(headers)
add_executable(Gyak4 main.c
        sources/ball.c
        sources/ball.h)
