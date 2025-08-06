//
// Created by Stefan Petrov on 6.08.25.
//

#include <iostream>
#include <sstream>


void output_birthdate() {
    constexpr int date = 1999;
    constexpr int age = 26;
    std::cout << "Normal: " << '\t' << "Hex: " << '\t' << "Oct: " << '\t' << "Dec: " << '\n';
    std::cout << date << "\t\t" << std::hex << date << '\t' << std::oct << date << '\t' << std::dec << date << '\n';
    std::cout << age << "\t\t" << std::hex << age << '\t' << std::oct << age << '\t' << std::dec << age << '\n';
}

struct Point {
    int x;
    int y;
};

Point get_coordinates(const std::string &s) {
    std::istringstream is{s};
    Point xy;
    char left_paren, comma, right_paren;
    is >> left_paren >> xy.x >> comma >> xy.y >> right_paren;
    if (!is || left_paren != '(' || comma != ',' || right_paren != ')') throw std::runtime_error("Format error");
    return xy;
}

int main() {
    try {
        auto c1 = get_coordinates("(2,3)");
        std::cout << std::format("c1: ({}, {})\n", c1.x, c1.y);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        auto c2 = get_coordinates("( 200, 300) ");
        std::cout << std::format("c2: ({}, {})\n", c2.x, c2.y);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        auto c3 = get_coordinates("100,400");
        std::cout << std::format("c3: ({}, {})\n", c3.x, c3.y);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
