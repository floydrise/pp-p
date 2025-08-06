//
// Created by Stefan Petrov on 6.08.25.
//
#include <fstream>
#include <iostream>

void write_file() {
    std::ofstream ofs{"new_file.txt", std::ios::app};
    std::string inp;
    std::cout << "Write a sentence:" << '\n';
    getline(std::cin, inp);
    ofs << inp << '\n';
}

void read_file() {
    std::ifstream ifs{"new_file.txt"};
    std::string buffer;
    while (std::getline(ifs, buffer)) {
        std::cout << buffer << std::endl;
    }
}

int main() {
    write_file();
    read_file();
    return 0;
}
