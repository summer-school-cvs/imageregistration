cmake_minimum_required(VERSION 3.16)

project(ImgageRegistration)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(source/core)
add_subdirectory(source/multiregistration)

add_subdirectory(source/features)
add_subdirectory(source/featuring)
