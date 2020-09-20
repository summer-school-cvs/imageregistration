cmake_minimum_required(VERSION 3.16)

project(Homography)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        include/stitching/homography/homography.h

        src/homography.cpp
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    )

target_link_libraries(${PROJECT_NAME}
        core
    ) 
	
add_subdirectory(tests)
	