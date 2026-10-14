#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <SmartString.h>

int main() {
    using namespace Utilities;
    std::ifstream input_file("/mnt/c/Users/Matt/CLionProjects/advent_of_code/year_2025/Day_02/input_data/input.txt");
    std::string   l;
    std::vector<std::pair<int64_t, int64_t>> ranges{};
    while(std::getline(input_file, l))
    {
        SmartString line(l);
        auto splitLine = line.split<SmartString>(',');
        for (const auto& range_str : splitLine) {
            auto range = range_str.split<SmartString>('-');
            ranges.emplace_back(range.front().convert<int64_t>(), range.back().convert<int64_t>());
        }
    }
    input_file.close();


    int num_invalid_ids = 0;
    int64_t invalid_id_sum = 0;
    bool found_big_num = false;
    for (const auto& [begin, end] : ranges) {
        for (int64_t i = begin; i <= end; ++i) {
            if (i > std::numeric_limits<int32_t>::max()) {
                found_big_num = true;
            }
            SmartString num_str{i};
            if (num_str.length() < 2 || num_str.length() % 2 != 0) {
                continue;
            }

            auto midpoint = num_str.length() / 2;
            auto first_half = num_str.getSubstring(0, midpoint - 1);
            auto temp = first_half.convert<int64_t>();
            if (num_str.findSubstring(midpoint, first_half) != std::string::npos) {
                num_invalid_ids++;
                invalid_id_sum += i;
            }
        }
    }

    std::cout << num_invalid_ids << std::endl;
    std::cout << invalid_id_sum << std::endl;

    return 0;
}
