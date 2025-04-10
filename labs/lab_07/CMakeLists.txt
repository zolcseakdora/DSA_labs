cmake_minimum_required(VERSION 3.29)
project(lab_07 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_07 main.c
        array/functions.c
        array/functions.h
        stack/stack.c
        stack/stack.h
        simplequeue/simplequeue.c
        simplequeue/simplequeue.h
        circularqueue/circularqueue.c
        circularqueue/circularqueue.h
)
