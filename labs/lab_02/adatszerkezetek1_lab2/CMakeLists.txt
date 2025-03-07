cmake_minimum_required(VERSION 3.30)
project(adatszerkezetek1_lab2 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(adatszerkezetek1_lab2 main.c
      headers/utils.h
      sources/utils.c)
