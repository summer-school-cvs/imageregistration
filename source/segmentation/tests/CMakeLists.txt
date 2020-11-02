cmake_minimum_required(VERSION 3.16)

project(segmentation_test)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        segmentation_test.cpp
        )

target_link_libraries(${PROJECT_NAME}
    gtest_main)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

target_link_libraries(${PROJECT_NAME} segmentation)

add_test(NAME segmentation COMMAND ${PROJECT_NAME})
