cmake_minimum_required(VERSION 3.16)

project(core)

find_package(OpenCV REQUIRED)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        include
    )

target_link_libraries(${PROJECT_NAME}
    INTERFACE
        opencv_core
    )
