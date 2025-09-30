cmake_minimum_required(VERSION 3.10)

project(lab_5)

include_directories(include)

set(SOURCES
    source/main.cpp
source/functions.cpp
)

set(HEADERS
    headers/Object.h
    headers/function.h
)

add_executable(lab_5 ${SOURCES})