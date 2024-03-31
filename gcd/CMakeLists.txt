cmake_minimum_required(VERSION 3.24)
project(gcd)
set(CMAKE_C_STANDARD 99)

set(SOURCES
    src/main.c
    src/gcd.c
)    

add_executable(gcd ${SOURCES})
target_include_directories(gcd PRIVATE ${PROJECT_SOURCE_DIR}/include)
