cmake_minimum_required(VERSION 3.26)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(libprg)

add_executable(untitled main.c)

target_link_libraries(untitled PUBLIC libprg)
