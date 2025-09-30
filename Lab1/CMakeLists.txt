cmake_minimum_required(VERSION 3.10)

project(lab_5)

include_directories(include)

set(SOURCES
    sources/main.cpp
    sources/menu.cpp
)

set(HEADERS
    headers/menu.h
    headers/function.h
)

add_executable(lab_5 ${SOURCES})