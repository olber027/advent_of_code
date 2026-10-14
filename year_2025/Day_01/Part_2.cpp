#include <iostream>
#include <fstream>
#include <vector>
#include <SmartString.h>

int main() {
    std::ifstream input_file("/mnt/c/Users/Matt/CLionProjects/advent_of_code/year_2025/Day_01/input_data/input.txt");
    std::string   l;
    std::vector<int> cmds;
    while(std::getline(input_file, l))
    {
        Utilities::SmartString line(l);
        if (line[0] == 'L') {
            line[0] = '-';
        } else {
            line[0] = ' ';
        }
        line.strip();
        cmds.push_back(line.convert<int>());
    }
    input_file.close();

    int current_location = 50;
    int password = 0;

    auto advance = [&](const int amount) {
        current_location += amount;
        if (current_location == 100) {
            current_location = 0;
        }
        if (current_location == -1) {
            current_location = 99;
        }
        if (current_location == 0) {
            password++;
        }
    };

    for (const auto& cmd : cmds) {
        auto dir = cmd < 0 ? -1 : 1;
        for (int i = 0; i < std::abs(cmd); i++) {
            advance(dir);
        }
    }

    std::cout << password << std::endl;

    return 0;
}
