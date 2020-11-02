cmake_minimum_required(VERSION 3.16)

project(segmentation)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        include/stitching/segmentation/segmentation.h

        src/segmentation.cpp
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    )

target_link_libraries(${PROJECT_NAME}
        core
    )

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

