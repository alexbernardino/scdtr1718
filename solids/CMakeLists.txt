cmake_minimum_required(VERSION 3.8)
project(solids)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        blocks1.cpp
        cube1.h
        cylinder1.h
        solid1.h friends.h totalmass.h)

add_executable(solids ${SOURCE_FILES})