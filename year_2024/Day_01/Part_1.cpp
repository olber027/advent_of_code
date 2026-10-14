#include <iostream>
#include <fstream>
#include <vector>
#include <SmartString.h>
#include <algorithm>
#include <cmath>

int main() {
    std::ifstream input_file("/mnt/c/Users/Matt/CLionProjects/advent_of_code/2024/Day_01/input_data/input.txt");
    std::string   l;
    std::vector<int> left;
    std::vector<int> right;
    while(std::getline(input_file, l))
    {
        Utilities::SmartString line(l);
        auto splitLine = line.split<Utilities::SmartString>();
        left.push_back(splitLine[0].convert<int>());
        right.push_back(splitLine[3].convert<int>());
    }
    input_file.close();

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int total = 0;
    for(int i = 0; i < left.size(); i++)
    {
        total += std::abs(left[i] - right[i]);
        std::cout << left[i] << " " << right[i] << std::endl;
    }

    std::cout << total << std::endl;

    return 0;
}
