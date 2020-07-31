
cmake_minimum_required(VERSION 3.16)

project(Features)

find_package(OpenCV REQUIRED)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        source/features.cpp
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
        ../core/include/stitching/core/
    )

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        opencv_core
    )
