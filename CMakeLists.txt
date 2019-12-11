cmake_minimum_required(VERSION 3.5)


project(HashMap)

#include the header hashmap.h
include_directories(include)

#can manually add the sources
set(SOURCES src/main.cpp)

#is used to add the sources files to the project
file(GLOB SOURCES "src/*.cpp")

add_executable(HashMap ${SOURCES} )