cmake_minimum_required(VERSION 3.24)
project(stack)
set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
add_executable(test-client src/main.c src/stack.c)
