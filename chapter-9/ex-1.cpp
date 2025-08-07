#include <fstream>
#include <iostream>
// Write a program that reads a text file and converts its input to all lowercase, producing a new file.

std::string to_lower(const std::string &str) {
    std::string buffer;
    for (const auto ch: str) {
        buffer += std::tolower(ch);
    }
    return buffer;
};

int main() {
    std::ifstream ifs{"upper_case.txt"};
    std::ofstream ofs{"lower_case.txt"};
    std::string buffer;
    while (std::getline(ifs, buffer)) {
        ofs << to_lower(buffer) << '\n';
    }
    return 0;
}
