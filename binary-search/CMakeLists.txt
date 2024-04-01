cmake_minimum_required(VERSION 3.24)
project(binary-search)
set(CMAKE_C_STANDARD 99)

set (SOURCES
    src/main.c
    src/binary_search.c        
)

add_executable(binary-search ${SOURCES})
target_include_directories(binary-search PRIVATE ${PROJECT_BINARY_DIR}/include)
