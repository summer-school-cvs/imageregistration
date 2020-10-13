cmake_minimum_required(VERSION 3.16)

project(stitcher)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        src/typedeclarations.cpp
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    )

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        featuring
        matching
        homography
        warping
        simplestitcher
        main
    )
