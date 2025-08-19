cmake_minimum_required(VERSION 3.31)
project(chapter_12)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(chapter_12 main.cpp
        exercises/drill/B1.h
        exercises/drill/B1.cpp)
target_link_libraries(chapter_12
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

