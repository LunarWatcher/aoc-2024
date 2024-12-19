cmake_minimum_required(VERSION 3.10)
project(aoc-2024)

set (CMAKE_CXX_STANDARD 23)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
add_subdirectory(tests)

add_custom_target(run
    COMMAND aoc-2024
    DEPENDS aoc-2024
    COMMENT "Run aoc-2024")
add_custom_target(test
    COMMAND tests
    DEPENDS tests
    COMMENT "Test aoc-2024")
# vim:ft=cmake
