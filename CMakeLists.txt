cmake_minimum_required(VERSION 4.2.3)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_SHARED_LIBS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

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

find_package(Qt6 CONFIG REQUIRED COMPONENTS Core Gui Qml Quick)

qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/gui)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/arch/x86/components)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/arch/x86/models)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/utils)

qt_add_qml_module(${PROJECT_NAME}
  URI App
  VERSION 0.0.1
  # FIX Throws error with qt/6.12: "ninja: error:
  # '.qt/qml_imports/qbki-emu_build.cmake', needed by
  # '.qt/qtconfs/qbki-emu_qt.part.conf', missing and no known rule to make it"
  # <>
  NO_IMPORT_SCAN
  # </>
  SOURCES
    src/gui/arch/x86/models/CPUModel.h
    src/gui/arch/x86/models/CPUModel.cpp
    src/gui/utils/theme.h
  QML_FILES
    src/gui/arch/x86/components/CPU.qml
    src/gui/Main.qml
)

target_sources(${PROJECT_NAME}
  PUBLIC
    FILE_SET cpp_modules
    TYPE CXX_MODULES FILES ${SOURCES_MODULES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick)
