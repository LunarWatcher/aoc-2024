#pragma once

#include "Day.hpp"

#include <aoc/input/FileReader.hpp>

namespace aoc {

class Day1 : public Day {
private:
    std::vector<int> listA, listB;
public:
    void parse() override;
    std::variant<std::string, int64_t> part1() override;
    std::variant<std::string, int64_t> part2() override;
};

}
