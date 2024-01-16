cmake_minimum_required(VERSION 3.23)
project(csce_2110_project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Code)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(csce_2110_project_1
        Commercial.cpp
        Commercial.h
        Industrial.cpp
        Industrial.h
        main.cpp
        Pollution.cpp
        Pollution.h
        Residential.cpp
        Residential.h
        Cell.cpp
        Cell.h
        Ducks.cpp
        Ducks.h
        School.cpp
        School.h

)