cmake_minimum_required(VERSION 3.30)
project(Gyak1 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)
add_executable(Gyak1 main.c
        sources/labdak.c
        headers/labdak.h)
