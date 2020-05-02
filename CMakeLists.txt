# ///////////////////////////////////////////////////////////////////////////////////////
# AUTHOR : Hethsron Jedaël BOUEYA
#
#                                   LICENCE AGREEMENT
#                       Copyright (c) 2020, UHA - UNIVERSITE DE HAUTE ALSACE
#                        ENSISA - Ecole Nationale Supérieure du Sude Alsace
# ///////////////////////////////////////////////////////////////////////////////////////
cmake_minimum_required (VERSION 3.8)

# Define project name
project("sugeno")

# Define program name
set(FRAMEWORK_PROG_NAME sugeno)

# Adding dependency to google test framework
add_subdirectory(Google_tests)

# Check operating system
if(UNIX)
    if (CMAKE_COMPILER_IS_GNUCC)
        if(CMAKE_BUILD_TYPE MATCHES DEBUG)
            message("-- Debug mode")
            set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
        else(CMAKE_BUILD_TYPE MATCHES DEBUG)
            message("-- Release mode")
            set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast")
        endif(CMAKE_BUILD_TYPE MATCHES DEBUG)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
        set(CMAKE_CXX_STANDARD 11)
        set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
    endif (CMAKE_COMPILER_IS_GNUCC)
elseif(APPLE)
    if (MINGW)
        if(CMAKE_BUILD_TYPE MATCHES DEBUG)
            message("-- Debug mode")
            set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
        else(CMAKE_BUILD_TYPE MATCHES DEBUG)
            message("-- Release mode")
            set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast")
        endif(CMAKE_BUILD_TYPE MATCHES DEBUG)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
        set(CMAKE_CXX_STANDARD 11)
        set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
    endif(MINGW)
elseif(WIN32)
    if (MSVC)
        if(CMAKE_BUILD_TYPE MATCHES DEBUG)
            message("-- Debug mode")
            set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
        else(CMAKE_BUILD_TYPE MATCHES DEBUG)
            message("-- Release mode")
            set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
        endif(CMAKE_BUILD_TYPE MATCHES DEBUG)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
        set(CMAKE_CXX_STANDARD 11)
        set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
    elseif(MINGW)
        if(CMAKE_BUILD_TYPE MATCHES DEBUG)
            message("-- Debug mode")
            set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
        else(CMAKE_BUILD_TYPE MATCHES DEBUG)
            message("-- Release mode")
            set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
        endif(CMAKE_BUILD_TYPE MATCHES DEBUG)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
        set(CMAKE_CXX_STANDARD 11)
        set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
    endif (MSVC)
endif()

# Set variable for include directory
set(FRAMEWORK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/header)

# Include dynamically directory of headers
include_directories(${FRAMEWORK_INCLUDE_DIR})

# Configure headers dependencies
message("-- Loading headers")
file(GLOB_RECURSE FRAMEWORK_HEADERS CMAKE_CONFIGURE_DEPENDS
        ${FRAMEWORK_INCLUDE_DIR}/core/*.hpp
        ${FRAMEWORK_INCLUDE_DIR}/evolution/*.hpp
        ${FRAMEWORK_INCLUDE_DIR}/exceptions/*.hpp
        ${FRAMEWORK_INCLUDE_DIR}/factory/*.hpp
        ${FRAMEWORK_INCLUDE_DIR}/fuzzy/*.hpp
        )

message(${FRAMEWORK_HEADERS})

if ("${FRAMEWORK_HEADERS}" STREQUAL "")
    message("-- Fatal error - cannot access to headers")
else("${FRAMEWORK_HEADERS}" STREQUAL "")
    message("-- Headers have been loaded successfully")
endif("${FRAMEWORK_HEADERS}" STREQUAL "")

# Set variable for source directory
set(FRAMEWORK_SRCS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Configure sources dependencies
message("-- Loading sources")
FILE(GLOB_RECURSE FRAMEWORK_SRCS CMAKE_CONFIGURE_DEPENDS
        ${FRAMEWORK_SRCS_DIR}/*.cpp
        )

if ("${FRAMEWORK_SRCS}" STREQUAL "")
    message("-- Fatal error - cannot access to headers")
else("${FRAMEWORK_SRCS}" STREQUAL "")
    message("-- Headers have been loaded successfully")
endif("${FRAMEWORK_SRCS}" STREQUAL "")

# Set executable output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Adding executable
add_executable(${FRAMEWORK_PROG_NAME} ${FRAMEWORK_SRCS} header/core/expressionFactory.hpp header/fuzzy/fuzzyFactory.hpp header/fuzzy/not.hpp header/core/naryexpressionmodel.hpp header/fuzzy/shape.hpp header/fuzzy/mamdanidefuzz.hpp header/fuzzy/cogdefuzz.hpp header/fuzzy/sugenoconclusion.hpp Google_tests/Unitest.cpp)