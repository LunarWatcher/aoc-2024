#include "aoc/days/Day.hpp"

#include "aoc/days/Day1.hpp"
#include "aoc/days/Day2.hpp"
#include "aoc/days/Day3.hpp"
#include "aoc/days/Day4.hpp"
#include "aoc/days/Day5.hpp"

#include <vector>
#include <memory>
#include <iostream>
#include <format>
#include <chrono>

std::pair<std::variant<std::string, int64_t>, double> getDurationAndResults(std::function<std::variant<std::string, int64_t>()> func) {
    auto start = std::chrono::high_resolution_clock::now();
    auto res = func();
    auto end = std::chrono::high_resolution_clock::now();
    return {
        res,
        std::chrono::duration<double, std::milli>(
            end - start
        ).count()
    };
}

void printPart(int partNum, std::pair<std::variant<std::string, int64_t>, double> res) {
    std::cout << "Part " << partNum << ": ";
    
    if (std::holds_alternative<std::string>(res.first)) {
        std::cout << std::format("{:<20}", std::get<std::string>(res.first));
    } else {
        std::cout << std::format("{:<20}", std::get<int64_t>(res.first));
    }

    std::string colour;
    if (res.second <= 10.0) {
        colour = "0;255;0";
    } else if (res.second <= 100) {
        colour = "188;255;0";
    } else if (res.second <= 500) {
        colour = "255;240;0";
    } else if (res.second <= 1000) {
        colour = "255;133;0";
    } else {
        colour = "255;0;0";
    }
    std::cout << "("
        << "\033[48;2;" << colour << "m"
        << "\033[38;5;232m"
        << std::format("{:>10}", res.second)
        << "ms"
        << "\033[0m"
        << ")"
        << std::endl;

}

int main() {
    std::cout << "Hewwo :3" << std::endl;

    //printPart(1, {0, 10});
    //printPart(1, {0, 100});
    //printPart(1, {0, 500});
    //printPart(1, {0, 1000});
    //printPart(1, {0, 69420});

#define DAY(N) std::make_shared<aoc::Day##N>()
    std::vector<std::shared_ptr<aoc::Day>> days = {
        DAY(1), DAY(2), DAY(3), DAY(4), DAY(5)
    };

    size_t dayID = 1;
    for (auto& day : days) {
        std::cout << "### Day " << dayID++ << " ###" << std::endl; 
        day->parse();
        printPart(1, getDurationAndResults([&]() { return day->part1(); }));
        printPart(2, getDurationAndResults([&]() { return day->part2(); }));
    }

}
