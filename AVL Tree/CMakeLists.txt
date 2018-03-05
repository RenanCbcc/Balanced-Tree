# cmake_minimum_required(VERSION <specify CMake version here>)
project(AVL_Tree C)

set(CMAKE_C_STANDARD 99)

add_executable(AVL_Tree main.c Tree.h Tree.c)