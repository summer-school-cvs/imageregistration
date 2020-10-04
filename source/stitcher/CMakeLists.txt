cmake_minimum_required(VERSION 3.16)

project(stitcher)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        include/stitching/stitcher/simplestitcher.h
        include/stitching/stitcher/typedefinitions.h

        src/simplestitcher.cpp
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    )

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        main
        featuring
        matching
        homography
        warping
    )
