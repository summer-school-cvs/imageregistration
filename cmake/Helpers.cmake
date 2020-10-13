macro(add_if_not_exist target path)
    if(NOT TARGET ${target})
        if(IS_ABSOLUTE ${path})
            get_filename_component(TARGET_PATH ${path} ABSOLUTE ${CMAKE_CURRENT_LIST_DIR})
        else()
            get_filename_component(TARGET_PATH ${path} REALPATH ${CMAKE_CURRENT_LIST_DIR})
        endif()

        if(NOT EXISTS "${TARGET_PATH}/CMakeLists.txt")
            message( FATAL_ERROR "File \"${TARGET_PATH}/CMakeLists.txt\" not found." )
        else()
            add_subdirectory(${TARGET_PATH} ${target})
        endif()
    else()
    endif()
endmacro()

macro(git_description DESCRIPTOR TAG COUNT)
    find_package(Git)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} describe
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE ${DESCRIPTOR}
            OUTPUT_STRIP_TRAILING_WHITESPACE)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} describe --always --abbrev=0
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE ${TAG}
            OUTPUT_STRIP_TRAILING_WHITESPACE)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} rev-list ${${TAG}}..HEAD --count
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE ${COUNT}
            OUTPUT_STRIP_TRAILING_WHITESPACE)
endmacro()
