#include "Day3.hpp"
#include "aoc/input/FileReader.hpp"

#include <iostream>
#include <stdexcept>

namespace aoc {

void Day3::parse() {
    this->program = FileReader::rawReadFileToString("day3.txt");
}

Day::Result Day3::part1() {
    int64_t sum = 0;

    size_t idx = 0;
    size_t nidx = 0;
    while ((nidx = this->program.find("mul(", idx)) != std::string::npos) {
        // Consume mul(
        sum += multiply(this->program, idx, nidx);
    } 

    return sum;
}
int64_t Day3::multiply(const std::string& src, size_t& idx, size_t matchIdx) {

    matchIdx += 4;
    idx = matchIdx;
    // Find )
    auto close = this->program.find(')', matchIdx);
    if (close - matchIdx > 8) {
        // Closing bracket invalid
        return 0;
    }

    // Find ,
    auto comma = this->program.find(',', matchIdx);
    if (comma > close) {
        // Comma after close, statement invalid
        return 0;
    }

    auto a = std::stoll(this->program.substr(matchIdx, comma - matchIdx));
    auto b = std::stoll(this->program.substr(comma + 1, close - comma - 1));

    return a * b;
}

std::pair<size_t, size_t> Day3::findFirstOf(const std::string& source, size_t start, const std::vector<std::string>& candidates) {
    size_t idx = std::string::npos;
    size_t match;

    for (size_t i = 0; i < candidates.size(); ++i) {
        const auto& substr = candidates.at(i);
        auto next = source.find(substr, start);
        if (next < idx) {
            idx = next;
            match = i;
        }
    }

    return {idx, match};
}

Day::Result Day3::part2() {
    std::vector<std::string> substrs = {"mul(", "do()", "don't()"};
    int64_t sum = 0;

    size_t idx = 0;
    bool enabled = true;

    while (true) {
        auto [nidx, match] = findFirstOf(this->program, idx, substrs);

        if (nidx == std::string::npos) {
            break;
        }

        switch (match) {
        case 0:
            if (enabled) {
                sum += multiply(this->program, idx, nidx);
            } else {
                idx = nidx + 4;
            }
            break;
        case 1:
            enabled = true;
            idx = nidx + 4;
            break;
        case 2:
            enabled = false;
            idx = nidx + 7;
            break;
        default:
            throw std::runtime_error("You're an idiot");
        }

    }

    return sum;
}

}
