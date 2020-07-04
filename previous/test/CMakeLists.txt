cmake_minimum_required(VERSION 3.14)

project(registration_test)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        test.cpp
        homography/homography.cpp
        featuring/implementation_test.cpp
	    matching/matching.cpp
		warping/warping.cpp
        pipeline/pipeline.cpp)

target_link_libraries(${PROJECT_NAME}
    gtest_main)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        TEST_DATA_DIR="${CMAKE_CURRENT_LIST_DIR}/pics"
    )

add_test(NAME all_tests COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} imgreg)
