cmake_minimum_required(VERSION 3.29)
project(lab_06 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(lab_06 main.c
        simplequeue.c
        simplequeue.h
        circlequeue.c
        circlequeue.h
)
