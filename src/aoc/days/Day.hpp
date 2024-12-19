#pragma once

#include <string>
#include <variant>
#include <cstdint>
#include <vector>

namespace aoc {


class Day {
public:
    using Result = std::variant<std::string, int64_t>;
    using IntMap = std::vector<std::vector<int64_t>>;
    using CharMap = std::vector<std::vector<char>>;

    virtual ~Day() = default;

    virtual void parse() = 0;
    virtual Result part1() = 0;
    virtual Result part2() = 0;
};

#define DAY_IMPL void parse() override; \
    Day::Result part1() override; \
    Day::Result part2() override;

}
