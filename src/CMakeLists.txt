add_library(aoc-2024src STATIC 
    aoc/days/Day1.cpp
    aoc/days/Day2.cpp
    aoc/days/Day3.cpp
    aoc/days/Day4.cpp
    aoc/days/Day5.cpp

    aoc/input/FileReader.cpp
)

# TODO: Figure out if poolstl is a viable replacement for this intel crap
if (UNIX)
    find_package(
        TBB
    )
    if (TBB_FOUND)
        message(STATUS "Found libtbb -- linking")
        target_link_libraries(aoc-2024src PUBLIC TBB::tbb)

        if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libstdc++")
        endif()
    else()
        message(WARNING "Failed to find tbb. Multithreading is not supported")
    endif()
endif()

add_executable(aoc-2024 aoc/Main.cpp)
target_link_libraries(aoc-2024
    aoc-2024src
)

target_include_directories(aoc-2024src PUBLIC ./)

# vim:ft=cmake
