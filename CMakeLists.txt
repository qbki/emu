cmake_minimum_required(VERSION 4.2.3)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_SHARED_LIBS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_compile_options("-Wall")
add_compile_options("-Wextra")
add_compile_options("-Wpedantic")
add_compile_options("-pedantic-errors")
add_compile_options("-fno-exceptions")
add_compile_options("-stdlib=libc++")

project(qbki-emu VERSION 0.0.1 LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE SOURCES_MODULES src/*.cppm)
list(FILTER SOURCES EXCLUDE REGEX ".tests.cpp$")
list(FILTER SOURCES_MODULES EXCLUDE REGEX ".*tests-utils.*")

add_executable(${PROJECT_NAME} ${SOURCES})

target_sources(${PROJECT_NAME}
  PUBLIC
    FILE_SET cpp_modules
    TYPE CXX_MODULES FILES ${SOURCES_MODULES})
