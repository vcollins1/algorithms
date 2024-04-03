cmake_minimum_required(VERSION 3.24)
project(flips)
set(CMAKE_C_STANDARD 99)
add_executable(flips main.c ../counter/src/counter.c)
