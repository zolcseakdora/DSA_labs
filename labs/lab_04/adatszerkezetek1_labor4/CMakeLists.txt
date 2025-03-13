cmake_minimum_required(VERSION 3.30)
project(adatszerkezetek1_labor4 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(adatszerkezetek1_labor4 main.c
        sources/array.c
        headers/array.h
)
