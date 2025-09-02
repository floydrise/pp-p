cmake_minimum_required(VERSION 3.31)
project(chapter_15)

set(CMAKE_CXX_STANDARD 23)

add_executable(chapter_15 main.cpp
        Link.h
        Link.cpp
        Linked_list.cpp)
