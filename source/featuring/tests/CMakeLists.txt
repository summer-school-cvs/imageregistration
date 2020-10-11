cmake_minimum_required(VERSION 3.16)

project(Featuring_Test)

find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
        PRIVATE
            featuring_test.cpp
        )

target_link_libraries(${PROJECT_NAME}
            featuring
            opencv_core
            gtest_main
        )

add_test(NAME featuring COMMAND ${PROJECT_NAME})

