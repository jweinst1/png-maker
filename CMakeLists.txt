cmake_minimum_required(VERSION 3.6)

project(pngmaker)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

message(STATUS "Performing required lib actions")

include(FindZLIB)
if(ZLIB_FOUND)
    message(STATUS "Found zlib")
else(ZLIB_FOUND)
    message(FATAL_ERROR "Did not find zlib, this is required")
endif(ZLIB_FOUND)

include(FINDPNG)
if(PNG_FOUND)
    message(STATUS "Found png")
    add_definitions(${PNG_DEFINITIONS})
    include_directories(${PNG_INCLUDE_DIRS})
else(PNG_FOUND)
    message(FATAL_ERROR "Did not find png, this is required")
endif(PNG_FOUND)

function(prepare_png)
    foreach(targ ${ARGV})
       target_link_libraries(${targ} ${PNG_LIBRARIES})
    endforeach(targ ${ARGV})
endfunction(prepare_png)

add_library(write_pngs STATIC write_pngs.c)
prepare_png(write_pngs)

add_executable(test_bw_img test_bw_img.c)
target_link_libraries(test_bw_img PUBLIC write_pngs)

add_executable(bw_100_sq bw_100_sq.c)
target_link_libraries(bw_100_sq PUBLIC write_pngs)

add_executable(bwpix bwpix.c)
target_link_libraries(bwpix PUBLIC write_pngs)
