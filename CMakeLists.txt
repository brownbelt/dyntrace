cmake_minimum_required(VERSION 3.9)

include(cmake/tracer.cmake)
include(FindPkgConfig)

enable_language(ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

execute_process(COMMAND uname -m OUTPUT_VARIABLE arch OUTPUT_STRIP_TRAILING_WHITESPACE)

pkg_check_modules(CAPSTONE capstone)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(dyntrace)
add_subdirectory(examples)
add_subdirectory(fasttp)
add_subdirectory(process)
add_subdirectory(inject)
add_subdirectory(tracers)
add_subdirectory(util)

add_subdirectory(ext)
