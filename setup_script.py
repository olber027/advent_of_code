import os

year = 2026

dir_root = """/mnt/c/Users/Matt/CLionProjects/advent_of_code/{year}""".format(year=year)

code_file_template = """#include <iostream>
#include <fstream>
#include <vector>
#include <SmartString.h>

int main() {{
    std::ifstream input_file("{base_dir_path}/input_data/test.txt");
    std::string   l;
    while(std::getline(input_file, l))
    {{
        Utilities::SmartString line(l);
        auto splitLine = line.split<Utilities::SmartString>();
    }}
    input_file.close();

    return 0;
}}
"""

cmake_template = """cmake_minimum_required(VERSION 3.20)

project({year}_Day_{day_number:02d} CXX)

add_executable(${{PROJECT_NAME}}_Part_1 Part_1.cpp)
target_link_libraries(${{PROJECT_NAME}}_Part_1 PUBLIC smart_string)

add_executable(${{PROJECT_NAME}}_Part_2 Part_2.cpp)
target_link_libraries(${{PROJECT_NAME}}_Part_2 PUBLIC smart_string)
"""

for day_num in range(1, 26):
    current_dir = dir_root + "/Day_{:02d}".format(day_num)
    print(current_dir)
    os.makedirs(current_dir, exist_ok=True)
    with open(current_dir + "/Part_1.cpp", "w+") as cpp_file:
        cpp_file.write(code_file_template.format(base_dir_path=current_dir))
    with open(current_dir + "/Part_2.cpp", "w+") as cpp_file:
        cpp_file.write(code_file_template.format(base_dir_path=current_dir))
    with open(current_dir + "/CMakeLists.txt", "w+") as cmake_file:
        cmake_file.write(cmake_template.format(day_number=day_num, year=year))
    input_dir = current_dir + "/input_data"
    os.makedirs(input_dir, exist_ok=True)
    with open(input_dir + "/input.txt", "w+") as input_file:
        input_file.write("\n")
    with open(input_dir + "/test.txt", "w+") as test_file:
        test_file.write("\n")
