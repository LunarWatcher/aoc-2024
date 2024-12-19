add_executable(tests 
    src/Bench.cpp

    src/Day4.cpp
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.7.1
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(tests Catch2::Catch2WithMain)
target_link_libraries(tests aoc-2024src)

# vim:ft=cmake
