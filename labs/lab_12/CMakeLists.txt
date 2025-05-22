cmake_minimum_required(VERSION 3.29)
project(lab_12 C)

set(CMAKE_C_STANDARD 23)
include_directories(headers)
add_executable(lab_12 main.c
        headers/book.h
        sources/book.c
        headers/contans.h
        sources/binary_search_tree.c
        headers/binary_search_tree.h
        sources/list.c
        headers/list.h
)
