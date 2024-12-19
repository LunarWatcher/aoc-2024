#include "FileReader.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>

#include <iostream>

namespace aoc {

std::string FileReader::rawReadFileToString(const std::string& file, bool stripNewlines) {
    static std::vector<std::filesystem::path> searchLocations = {
        "../input", 
        "./input",
        "../tests/input",
    };
    std::filesystem::path p;
    for (auto& dir : searchLocations) {
        if (std::filesystem::is_regular_file(dir / file)) {
            p = dir / file;
            break;
        }
    }

    std::ifstream f(p);
    if (!f) {
        throw std::runtime_error("Failed to find " + file);
    }
    std::stringstream out;

    std::string tmp;
    while (std::getline(f, tmp)) {
        out << tmp;
        if (!stripNewlines) {
            out << "\n";
        }
    }

    return out.str();
}

std::vector<std::string> FileReader::rawReadFile(const std::string& file) {
    static std::vector<std::filesystem::path> searchLocations = {
        "../input", 
        "./input",
        "../tests/input",
    };
    std::filesystem::path p;
    for (auto& dir : searchLocations) {
        if (std::filesystem::is_regular_file(dir / file)) {
            p = dir / file;
            break;
        }
    }

    std::ifstream f(p);
    if (!f) {
        throw std::runtime_error("Failed to find " + file);
    }
    std::vector<std::string> out;

    std::string tmp;
    while (std::getline(f, tmp)) {
        out.push_back(tmp);
    }

    return out;
}

std::pair<std::vector<int>, std::vector<int>> FileReader::parseFileToVecPair(const std::string& file) {
    auto in = rawReadFile(file);
    std::vector<int> a;
    std::vector<int> b;

    a.reserve(in.size());
    b.reserve(in.size());

    for (auto& line : in) {
        std::stringstream ss(line);
        int a1;
        int b1;
        ss >> a1 >> b1;

        a.push_back(a1);
        b.push_back(b1);
    }

    return { a, b };
}

namespace FileReader {

}

}
