cmake_minimum_required(VERSION 3.6)

project(pngmaker)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

message(STATUS "Performing required lib actions")

include(FindZLIB)

include(FINDPNG)

message("Done")
