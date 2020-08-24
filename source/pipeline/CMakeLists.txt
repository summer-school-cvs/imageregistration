cmake_minimum_required(VERSION 3.16)

project(Pipeline)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        include/stitching/pipeline/pipeline.h

        src/pipeline.cpp
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    )

target_link_libraries(${PROJECT_NAME}
        core
    )

add_subdirectory(test)