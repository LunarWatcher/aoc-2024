add_library(aoc-2024src STATIC 
    aoc/days/Day1.cpp
    aoc/days/Day2.cpp
    aoc/days/Day3.cpp
    aoc/days/Day4.cpp

    aoc/input/FileReader.cpp
)

add_executable(aoc-2024 aoc/Main.cpp)
target_link_libraries(aoc-2024
    aoc-2024src
)

target_include_directories(aoc-2024src PUBLIC ./)

# vim:ft=cmake
