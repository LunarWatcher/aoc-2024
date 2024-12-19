#pragma once

#include "aoc/days/Day.hpp"

namespace aoc {


class Day5 : public Day {
private:
    std::string fn = "day5.txt";
public:
    struct Input {
        std::vector<std::pair<int64_t, int64_t>> rules;
        std::vector<std::vector<int64_t>> sequences;
    };
    Day5() = default;
    Day5(const std::string& fn) : fn(fn) {}

    Input data;

    DAY_IMPL
};

}
