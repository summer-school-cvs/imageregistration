cmake_minimum_required(VERSION 3.16)

project(Warping)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        include/stitching/warping/warping.h

        src/warping.cpp
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    )

target_link_libraries(${PROJECT_NAME}
        core
    )