#include "Day4.hpp"
#include "aoc/input/FileReader.hpp"

namespace aoc {

void Day4::parse() {
    map = FileReader::parseFileToVec<std::vector<char>>(
        sourceName,
        &FileReader::Convert::str2numvec<char>
    );
}

Day::Result Day4::part1() {
    int64_t appearances = 0;
    size_t height = map.size();
    size_t width = map.at(0).size();

    for (size_t y = 0; y < height; ++y) {
        auto row = map.at(y);
        for (size_t x = 0; x < width; ++x) {
            auto ch = row.at(x);

            if (ch == 'X') {
                // Horizontal {{{
                if (x >= 3) {
                    appearances += (int64_t) isXmas(
                        ch,
                        row.at(x - 1),
                        row.at(x - 2),
                        row.at(x - 3)
                    );
                }
                if (x < width - 3) {
                    appearances += (int64_t) isXmas(
                        ch,
                        row.at(x + 1),
                        row.at(x + 2),
                        row.at(x + 3)
                    );
                }
                // }}}
                // Vertical {{{
                if (y >= 3) {
                    appearances += (int64_t) isXmas(
                        ch,
                        map.at(y - 1).at(x),
                        map.at(y - 2).at(x),
                        map.at(y - 3).at(x)
                    );
                }

                if (y < height - 3) {
                    appearances += (int64_t) isXmas(
                        ch,
                        map.at(y + 1).at(x),
                        map.at(y + 2).at(x),
                        map.at(y + 3).at(x)
                    );
                }
                // }}}
                // Diagonal {{{
                
                // Top-left
                if (x >= 3 && y >= 3) {
                    appearances += (int64_t) isXmas(
                        ch,
                        map.at(y - 1).at(x - 1),
                        map.at(y - 2).at(x - 2),
                        map.at(y - 3).at(x - 3)
                    );

                }
                // top right
                if (x < width - 3 && y >= 3) {
                    appearances += (int64_t) isXmas(
                        ch,
                        map.at(y - 1).at(x + 1),
                        map.at(y - 2).at(x + 2),
                        map.at(y - 3).at(x + 3)
                    );
                }


                // Bottom right
                if (x < width - 3 && y < height - 3) {
                    appearances += (int64_t) isXmas(
                        ch,
                        map.at(y + 1).at(x + 1),
                        map.at(y + 2).at(x + 2),
                        map.at(y + 3).at(x + 3)
                    );
                }

                // Bottom left
                if (x >= 3 && y < height - 3) {
                    appearances += (int64_t) isXmas(
                        ch,
                        map.at(y + 1).at(x - 1),
                        map.at(y + 2).at(x - 2),
                        map.at(y + 3).at(x - 3)
                    );
                }

                // }}}
            }
        }
    }
    return appearances;
}

Day::Result Day4::part2() {
    int64_t appearances = 0;
    size_t height = map.size();
    size_t width = map.at(0).size();

    for (size_t y = 1; y < height - 1; ++y) {
        auto row = map.at(y);
        for (size_t x = 1; x < width - 1; ++x) {
            auto ch = row.at(x);

            if (ch == 'A') {
                appearances += (int64_t) (fuckingMasX(
                    map.at(y - 1).at(x - 1),
                    map.at(y + 1).at(x + 1)
                ) && fuckingMasX(
                    map.at(y + 1).at(x - 1),
                    map.at(y - 1).at(x + 1)
                ));
            }
        }
    }
    return appearances;
}

}
