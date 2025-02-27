cmake_minimum_required(VERSION 3.30)
project(adatszerkezet1_labor1 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(adatszerkezet1_labor1 main.c
        sources/functions.c
        headers/functions.h)
