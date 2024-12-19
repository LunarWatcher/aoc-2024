#include "aoc/days/Day4.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Day 4, test case 1", "[Day4]") {
    aoc::Day4 d("test1-day4.txt");
    d.parse();

    SECTION("Part 1") {
        auto part1 = d.part1();
        REQUIRE(std::holds_alternative<int64_t>(part1));
        REQUIRE(std::get<int64_t>(part1) == 18);
    }
}

TEST_CASE("Day 4, test case 2", "[Day4]") {
    aoc::Day4 d("test2-day4.txt");
    d.parse();

    SECTION("Part 1") {
        auto part1 = d.part1();
        REQUIRE(std::holds_alternative<int64_t>(part1));
        REQUIRE(std::get<int64_t>(part1) == 4);
    }
}
