cmake_minimum_required(VERSION 3.16)

project(featuring)

find_package(OpenCV REQUIRED)

option(STITCHING_ORB_FEATURING_ENABLE "" ON)
option(STITCHING_SURF_FEATURING_ENABLE "" ON)

macro(add_featuring_lib)
    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs SRC LIBS)
    cmake_parse_arguments(ARG_VAL "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN})

    add_library(${ARG_VAL_TARGET})
    target_sources(${ARG_VAL_TARGET} PRIVATE ${ARG_VAL_SRC})
    target_include_directories(${ARG_VAL_TARGET} PUBLIC include)
    target_link_libraries(${ARG_VAL_TARGET} ${ARG_VAL_LIBS})
endmacro()

if(STITCHING_ORB_FEATURING_ENABLE)
    add_featuring_lib(TARGET orbfeaturing
        SRC
            include/stitching/featuring/orb/orb_featuring.h
            source/orb/orb_featuring.cpp
        LIBS
            core
            ${OpenCV_LIBS}
        )
endif()

if(STITCHING_SURF_FEATURING_ENABLE)
    add_featuring_lib(TARGET surffeaturing
        SRC
            include/stitching/featuring/surf/surf_featuring.h
            source/surf/surf_featuring.cpp
        LIBS
            core
            ${OpenCV_LIBS}
        )
endif()

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME}
    INTERFACE
        $<$<TARGET_EXISTS:surffeaturing>:surffeaturing>
        $<$<TARGET_EXISTS:orbfeaturing>:orbfeaturing>
    )

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
