cmake_minimum_required(VERSION 3.24)
project(counter)
set(CMAKE_C_STANDARD 99)
add_executable(test-client src/main.c src/counter.c)
target_include_directories(test-client PRIVATE ${CMAKE_SOURCE_DIR}/include)
