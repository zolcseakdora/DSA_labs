cmake_minimum_required(VERSION 3.30)
project(adatszerkezetek1_lab3 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(adatszerkezetek1_lab3 main.c
        source/functions.c
        headers/functions.h
)
