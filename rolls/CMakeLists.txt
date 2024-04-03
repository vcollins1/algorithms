cmake_minimum_required(VERSION 3.24)
project(rolls)
set(CMAKE_C_STANDARD 99)
add_executable(rolls main.c ../counter/src/counter.c)
