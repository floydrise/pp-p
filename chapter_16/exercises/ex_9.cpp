#include <iostream>
#include <string>

std::string cat_dot_str(const std::string &s1, const std::string &s2, const std::string &separator) {
    return s1 + separator + s2;
}

std::string cat_dot_ptr(const char *s1, const char *s2, const char *separator) {
    std::string val;
    val.reserve(std::strlen(s1) + std::strlen(s2) + std::strlen(separator));
    return val + s1 + separator + s2;
}

int main() {
    std::string s1 = "Niels";
    std::string s2 = "Bohr";
    std::string separator = ".";

    char s3[] = "Niels";
    char s4[] = "Bohr";
    char separator2[] = ".";

    std::string val = cat_dot_str(s1, s2, separator);
    std::string val2 = cat_dot_ptr(s3, s4, separator2);

    std::cout << val << '\n';
    std::cout << val2 << '\n';
}
