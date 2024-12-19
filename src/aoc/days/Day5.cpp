#include "Day5.hpp"
#include "aoc/input/FileReader.hpp"
#include <cmath>
#include <execution>
#include <iostream>

namespace aoc {

void Day5::parse() {
    data = FileReader::parseFileToSpecial<Input>(
        fn,
        {
            [](Input& in, const std::string& line) {
                std::stringstream ss(line);
                int first;
                int second;
                char dump;
                ss >> first >> dump >> second;
                in.rules.push_back({first, second});
            },
            [](Input& in, const std::string& line) {
                in.sequences.push_back(FileReader::Convert::comstr2numvec<int64_t>(line));
            }
        }
    );
}

Day::Result Day5::part1() {
    int64_t sum = 0;
    for (auto& in : data.sequences) {
        for (size_t i = 0; i < in.size(); ++i) {
            auto num = in.at(i);

            for (auto& rule : data.rules) {

                if (rule.first == num) { 
                    for (size_t n = 0; n < in.size(); ++n) {
                        if (in.at(n) == rule.second) {
                            if (n < i) {
                                goto nextSeq;
                            } else if (n > i) {
                                goto nextRule;
                            }
                            continue;
                        }
                    } 
                } else {
                    // Rule not matched
                    continue;
                }

nextRule:
            }
        }
        {
            sum += in.at((size_t) std::floor((double) in.size() / 2.0));
        }
nextSeq: continue;
    }

    return sum;
}

Day::Result Day5::part2() {
    int64_t sum = 0;

    auto data = this->data;
    for (size_t i = 0; i < data.sequences.size(); ++i) {
        auto& in = data.sequences.at(i);
        std::stable_sort(in.begin(), in.end(), [&](auto a, auto b) -> bool {
            for (auto& rule : data.rules) {
                if (rule.first == b && rule.second == a) {
                    return false;
                } else if (rule.first == a && rule.second == b) {
                    return true;
                }
            }
            return false;
        });

        if (in != this->data.sequences.at(i)) {
            sum += in.at((size_t) std::floor((double) in.size() / 2.0));
        }
    }

    return sum;
}

}
