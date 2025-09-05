#include <iostream>
#include <string>

std::string cat_dot(const std::string &s1, const std::string &s2) {
    return s1 + "." + s2;
}

int main() {
    std::string s1 = "Niels";
    std::string s2 = "Bohr";

    std::string val = cat_dot(s1, s2);

    std::cout << val << '\n';
}
