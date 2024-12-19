#pragma once

#include <functional>
#include <string>
#include <vector>

namespace aoc::FileReader {

extern std::vector<std::string> rawReadFile(const std::string& file);

extern std::pair<std::vector<int>, std::vector<int>> parseFileToVecPair(const std::string& file);

}
