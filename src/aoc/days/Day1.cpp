#include "Day1.hpp"
#include "aoc/input/FileReader.hpp"
#include <algorithm>
#include <map>

namespace aoc {

void Day1::parse() {
    auto vecs = FileReader::parseFileToVecPair("day1.txt");
    this->listA = vecs.first;
    this->listB = vecs.second;

}

std::variant<std::string, int64_t> Day1::part1() {
    std::vector<int> a = listA;
    std::vector<int> b = listB;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int64_t sum = 0;

    for (size_t i = 0; i < a.size(); ++i) {
        sum += std::abs(b.at(i) - a.at(i));
    }

    return sum;
}

std::variant<std::string, int64_t> Day1::part2() {
    int64_t sum = 0;

    std::unordered_map<int64_t, int64_t> cache;
    cache.reserve(listA.size());
    for (auto& num : listB) {
        cache[num] += 1;
    }

    for (auto& num : listA) {
        sum += num * cache[num];
    }

    return sum;
}

}
