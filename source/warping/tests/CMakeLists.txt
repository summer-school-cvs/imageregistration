cmake_minimum_required(VERSION 3.16)

project(warping_test)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        warping_test.cpp
        )

target_link_libraries(${PROJECT_NAME}
    gtest_main)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

add_test(NAME warping_test COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} Warping)
