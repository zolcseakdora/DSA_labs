cmake_minimum_required(VERSION 3.29)
project(lab_10 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_10 main.c
        sources/binary_search_tree.c
        headers/binary_search_tree.h
        headers/contans.h)
