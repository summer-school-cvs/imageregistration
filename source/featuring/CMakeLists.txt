cmake_minimum_required(VERSION 3.16)

project(Featuring)

find_package(OpenCV REQUIRED)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        include/stitching/featuring/orb/orb_featuring.h
        include/stitching/featuring/surf/surf_featuring.h
        source/orb/orb_featuring.cpp
        source/surf/surf_featuring.cpp
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
        include/stitching/featuring/orb
        include/stitching/featuring/surf
        ../features/include/stitching
        ../core/include/stitching/core
    )

target_link_libraries(${PROJECT_NAME}
        core
        Features
        opencv_core
    )
