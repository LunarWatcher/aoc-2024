#pragma once

#include <string>
#include <variant>
#include <cstdint>

namespace aoc {

class Day {
public:
    virtual ~Day() = default;

    virtual void parse() = 0;
    virtual std::variant<std::string, int64_t> part1() = 0;
    virtual std::variant<std::string, int64_t> part2() = 0;
};

}
