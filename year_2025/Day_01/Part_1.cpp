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
    for (const auto& cmd : cmds) {
        current_location += cmd;
        if (current_location >= 100) {
            current_location = current_location % 100;
        } else {
            while (current_location < 0) {
                current_location += 100;
            }
        }
        if (current_location == 0) {
            password++;
        }
    }
    std::cout << password << std::endl;

    return 0;
}
