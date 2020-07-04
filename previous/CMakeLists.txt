cmake_minimum_required(VERSION 3.14)

if (NOT BUILD_NUMBER)
    set(BUILD_NUMBER "")
else()
    set(BUILD_NUMBER ".${BUILD_NUMBER}")
endif()

project(StudProj VERSION 0.0${BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(../thirdparty/googletest googletest)

enable_testing()
