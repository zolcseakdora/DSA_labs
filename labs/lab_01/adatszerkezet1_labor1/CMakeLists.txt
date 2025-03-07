cmake_minimum_required(VERSION 3.30)
project(adatszerkezet1_labor1 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(adatszerkezet1_labor1 main.c
        sources/functions.c
        headers/functions.h
headers/library.h)
target_link_libraries(adatszerkezet1_labor1 PRIVATE C:/Users/Dora/CLionProjects/DSA_labs/labs/lab_02/adatszerkezetek_lab2_library/cmake-build-debug/ibadatszerkezetek_lab2_library.a)