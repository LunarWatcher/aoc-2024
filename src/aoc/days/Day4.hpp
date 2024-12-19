#pragma once

#include "aoc/days/Day.hpp"

namespace aoc {

class Day4 : public Day {
private:
    CharMap map;
    bool isXmas(char x, char m, char a, char s) {
        return x == 'X' && m == 'M' && a == 'A' && s == 'S';
    }

    bool fuckingMasX(char a, char b) {
        return (a == 'M' && b == 'S')
            || (a == 'S' && b == 'M');
    }
    
    std::string sourceName = "day4.txt";

public:
    Day4() = default;
    Day4(const std::string& fn) : sourceName(fn) {}

    DAY_IMPL
};

}
