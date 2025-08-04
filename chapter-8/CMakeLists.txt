cmake_minimum_required(VERSION 3.31)
project(chapter_8)

set(CMAKE_CXX_STANDARD 23)

add_executable(chapter_8 date_struct.cpp
        Book.cpp
        book_exercises.cpp
        Patron.h
        Patron.cpp)
