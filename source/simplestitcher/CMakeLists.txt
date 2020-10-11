cmake_minimum_required(VERSION 3.16)

project(simplestitcher)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        include/stitching/stitcher/simplestitcher.h

        src/simplestitcher.cpp
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    )

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        core
    )
