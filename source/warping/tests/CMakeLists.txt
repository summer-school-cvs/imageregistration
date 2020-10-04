cmake_minimum_required(VERSION 3.16)

project(warping_test)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        warping_test.cpp
        )

target_link_libraries(${PROJECT_NAME}
    gtest_main
    warping
    )

add_test(NAME warping_test COMMAND ${PROJECT_NAME})

