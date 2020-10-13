function(downlad_from_gdrive)
    set(options)
    set(oneValueArgs ID RESULT)
    set(multiValueArgs)
    cmake_parse_arguments(G_OPT "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

    message(STATUS "Downloading file ${G_OPT_ID} from gdrive...")

    file(TO_NATIVE_PATH "${CMAKE_CURRENT_BINARY_DIR}/cookie_${G_OPT_ID}" COOKIE_FILE)

    find_program(CURL_EXEC NAMES curl REQUIRED)

    execute_process(COMMAND ${CURL_EXEC} -sc ${COOKIE_FILE} https://drive.google.com/uc?export=download&id=${G_OPT_ID}
        OUTPUT_VARIABLE HTML_CONTENT
        )

    string(REGEX MATCH "confirm=([A-Za-z0-9_]+)" CONFIRM_CODE ${HTML_CONTENT})
    string(REPLACE "confirm=" "" CONFIRM_CODE ${CONFIRM_CODE})

    execute_process(COMMAND ${CURL_EXEC} -Lb ${COOKIE_FILE} https://drive.google.com/uc?export=download&confirm=${CONFIRM_CODE}&id=${G_OPT_ID} -o ${G_OPT_RESULT})

    message(STATUS "File ${G_OPT_ID} downloaded.")
endfunction()
