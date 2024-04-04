cmake_minimum_required(VERSION 3.24)
project(linked-list)
set(CMAKE_C_STANDARD 99)
add_executable(test-client src/main.c src/linked-list.c)
