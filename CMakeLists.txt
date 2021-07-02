cmake_minimum_required(VERSION 3.17)

project(its-a-number C)

add_compile_definitions(LIBRARY_NAME=\"${PROJECT_NAME}\")

# Build options
option(BUILD_UNIT_TESTS "Build the lib tests" ON)
option(DYNAMIC_LIB "Should the lib be dynamically linked" OFF)

# Project dirs
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(TESTS_DIR ${CMAKE_SOURCE_DIR}/test)

# Deal with the Catalina implicit declaration bug
if(APPLE)
    message(STATUS "Added explicit sys include")
    include_directories(SYSTEM /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include)
endif(APPLE)

# Lib sources
set(SOURCES
    ${SOURCE_DIR}/bin.c
    ${SOURCE_DIR}/hex.c
    ${SOURCE_DIR}/kaktovik_inupiaq.c
    ${SOURCE_DIR}/oct.c
)

if(DYNAMIC_LIB)
    # Build a dynamic lib
    message(STATUS "Will build dynamic lib")
    add_library("${PROJECT_NAME}" ${SOURCES})
else(DYNAMIC_LIB)
    # Build a static lib
    message(STATUS "Will build static lib")
    add_library("${PROJECT_NAME}" STATIC ${SOURCES})
endif(DYNAMIC_LIB)

# Lib tests
if(BUILD_UNIT_TESTS)
    message(STATUS "Building with tests")

    set(TESTS
        ${TESTS_DIR}/test.c
        ${TESTS_DIR}/bin_test.c
        ${TESTS_DIR}/hex_test.c
        ${TESTS_DIR}/oct_test.c
    )

    # Include for the tests
    include_directories()

    set(TEST_NAME "${PROJECT_NAME}-test")

    add_executable(${TEST_NAME} ${TESTS})

    # Add lib as a dependency
    add_dependencies(${TEST_NAME} ${PROJECT_NAME})

    # Include 
    target_include_directories(${TEST_NAME} SYSTEM PUBLIC ${SOURCE_DIR})

    # Link
    find_library(PROJECT_LIB NAMES ${PROJECT_NAME}
                PATHS   ${CMAKE_SOURCE_DIR}
                        ${CMAKE_SOURCE_DIR}/build
    )

    target_link_libraries(${TEST_NAME} ${PROJECT_LIB})
endif(BUILD_UNIT_TESTS)
