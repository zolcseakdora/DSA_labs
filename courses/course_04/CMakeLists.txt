cmake_minimum_required(VERSION 3.29)
project(course_04 C)

set(CMAKE_C_STANDARD 23)

add_executable(course_04 main.c
        intarray_sources/intarray.c
        intarray_headers/intarray.h
        product_sources/product.c
        product_headers/product.h)
