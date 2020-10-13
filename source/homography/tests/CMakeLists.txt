cmake_minimum_required(VERSION 3.16)

project(homography_test)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        homography_test.cpp
        )

target_link_libraries(${PROJECT_NAME}
    gtest_main)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

target_link_libraries(${PROJECT_NAME} homography)

add_test(NAME homography COMMAND ${PROJECT_NAME})
