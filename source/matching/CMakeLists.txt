cmake_minimum_required(VERSION 3.16)

project(matching)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        include/stitching/matching/knn_matching.h

        src/knn_matching.cpp
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

