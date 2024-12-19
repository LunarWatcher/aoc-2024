#include "Day2.hpp"
#include "aoc/input/FileReader.hpp"
#include <cmath>
#include <optional>

namespace aoc {

void Day2::parse() {
    this->map = FileReader::parseFileToVec<std::vector<int64_t>>(
        "day2.txt", 
        &FileReader::Convert::str2intvec
    );
}

Day::Result Day2::part1() {
    int64_t safe = 0;

    for (auto& row : map) {
        bool unsafe = false;
        std::optional<bool> increasing;
        for (size_t i = 1; i < row.size(); ++i) {
            auto diff = row.at(i - 1) - row.at(i);
            if (!increasing.has_value()) {
                increasing = std::signbit(diff);
            }
            if (std::abs(diff) < 1 
                || std::abs(diff) > 3
                || increasing != std::signbit(diff)
            ) {
                unsafe = true;
                break;
            }
        }
        if (!unsafe) {
            ++safe;
        }
    }

    return safe;
}

Day::Result Day2::part2() {
    int64_t safe = 0;

    for (auto& row : map) {
        int offending = 0;
        std::optional<bool> increasing;
        for (size_t i = 1; i < row.size(); ++i) {
            auto diff = row.at(i - 1) - row.at(i);
            if (!increasing.has_value()) {
                increasing = std::signbit(diff);
            }
            if (std::abs(diff) < 1 
                || std::abs(diff) > 3
                || increasing != std::signbit(diff)
            ) {
                offending += 1;
            }
        }
        if (offending <= 1) {
            ++safe;
        }
    }

    return safe;
}

}
