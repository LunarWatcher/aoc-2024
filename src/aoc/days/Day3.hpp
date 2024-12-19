#pragma once

#include "aoc/days/Day.hpp"
namespace aoc {

class Day3 : public Day {
private:
    std::string program;

    std::pair<size_t, size_t> findFirstOf(const std::string& source, size_t start, const std::vector<std::string>& candidates);

    int64_t multiply(const std::string& src, size_t& idx, size_t matchIdx);
public:
    DAY_IMPL
};

}
