cmake_minimum_required(VERSION 3.24)
project(my_next_line)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(my_next_line
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c
        test.txt)
