#pragma once

#include <functional>
#include <string>
#include <vector>

namespace aoc::FileReader {

extern std::string rawReadFileToString(const std::string& file, bool stripNewlines = true);
extern std::vector<std::string> rawReadFile(const std::string& file);

extern std::pair<std::vector<int>, std::vector<int>> parseFileToVecPair(const std::string& file);

template <typename T>
extern std::vector<T> parseFileToVec(
    const std::string& file,
    std::function<T(const std::string& line)> lineParser
) {
    auto in = rawReadFile(file);

    std::vector<T> out;
    out.reserve(in.size());
    for (auto& line : in) {
        out.push_back(lineParser(line));
    }
    return out;
}

namespace Convert {

extern std::vector<int64_t> str2intvec(const std::string& line);

}

}
