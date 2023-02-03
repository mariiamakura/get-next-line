cmake_minimum_required(VERSION 3.24)
project(git_hub_line C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(git_hub_line
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c)
