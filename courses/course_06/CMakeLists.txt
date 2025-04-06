cmake_minimum_required(VERSION 3.29)
project(course_06 C)

set(CMAKE_C_STANDARD 23)

add_executable(course_06 main.c
        simple_queue_c/simple_queue.c
        simple_queue_h/simple_queue.h
        circle_queue_c/circle_queue.c
        circle_queue_h/circle_queue.h)
