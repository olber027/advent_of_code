#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <SmartString.h>

bool is_safe_decrementing(const std::vector<int>& levels)
{
    for(int i = 0; i < levels.size() - 1; i++)
    {
        int diff = levels[i] - levels[i + 1];
        if(diff <= 0 || diff > 3)
        {
            return false;
        }
    }
    return true;
}

bool is_safe_incrementing(const std::vector<int>& levels)
{
    for(int i = 0; i < levels.size() - 1; i++)
    {
        int diff = levels[i] - levels[i + 1];
        if(diff >= 0 || std::abs(diff) > 3)
        {
            return false;
        }
    }
    return true;
}

bool is_safe(const std::vector<int>& levels)
{
    if(levels.front() < levels.back())
    {
        return is_safe_incrementing(levels);
    }
    else if(levels.front() > levels.back())
    {
        return is_safe_decrementing(levels);
    }
    return false;
}

int main() {
    std::ifstream input_file("/mnt/c/Users/Matt/CLionProjects/advent_of_code/2024/Day_02/input_data/input.txt");
    std::string   l;
    std::vector<std::vector<int>> reports;
    while(std::getline(input_file, l)) {
        Utilities::SmartString line(l);
        auto splitLine = line.split<Utilities::SmartString>();
        std::vector<int> levels;
        for (const auto &num: splitLine) {
            levels.push_back(num.convert<int>());
        }
        reports.push_back(levels);
    }
    input_file.close();

    int num_safe_reports = 0;
    for(const auto& report : reports)
    {
        if(is_safe(report))
        {
            num_safe_reports++;
        }
    }

    std::cout << num_safe_reports << std::endl;

    return 0;
}
