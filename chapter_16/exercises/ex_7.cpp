#include <iostream>
#include <string>

std::string cat_dot(const char *s1, const char *s2) {
    std::string val;

    for (; *s1 != 0; s1++) {
        val += *s1;
    }
    val += ".";
    for (; *s2 != 0; s2++) {
        val += *s2;
    }
    return val;
}

std::string cat_dot_v2(const char *s1, const char *s2) {
    return std::string(s1) + "." + std::string(s2);
}

std::string cat_dot_v3(const char *s1, const char *s2) {
    std::string val;
    val.reserve(std::strlen(s1) + std::strlen(s2) + 1);
    return val + s1 + "." + s2;
}

int main() {
    char s1[] = "Niels";
    char s2[] = "Bohr";

    std::string val = cat_dot(s1, s2);
    std::string val2 = cat_dot_v2(s1, s2);
    std::string val3 = cat_dot_v3(s1, s2);
    std::cout << val << '\n';
    std::cout << val2 << '\n';
    std::cout << val3 << '\n';
}
