#include "aoc/days/Day5.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Day 5, test case 1", "[Day5]") {
    aoc::Day5 d("test1-day5.txt");
    d.parse();

    REQUIRE(d.data.rules.size() == 1);
    REQUIRE(d.data.sequences.size() == 1);
    REQUIRE(d.data.rules.at(0) == std::pair{1, 2});
    REQUIRE(d.data.sequences.at(0) == std::vector<int64_t>{1, 2, 3});

    SECTION("Part 1") {
        auto r = d.part1();

        REQUIRE(std::get<int64_t>(r) == 2);
    }
}

TEST_CASE("Day 5, test case 2", "[Day5]") {
    aoc::Day5 d("test2-day5.txt");
    d.parse();

    SECTION("Part 1") {
        auto r = d.part1();
        REQUIRE(std::get<int64_t>(r) == 143);
    }

    SECTION("Part 2") {
        auto r = d.part2();
        REQUIRE(std::get<int64_t>(r) == 123);
    }
}

TEST_CASE("Day 5, real input", "[Day5]") {
    aoc::Day5 d;
    d.parse();

    REQUIRE(d.data.rules.size() == 1176);
    REQUIRE(d.data.sequences.size() == 200);

    SECTION("Part 1") {

    }
}
