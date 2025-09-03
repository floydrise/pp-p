// when I tried this it only compiled using C++17, not C++23
#include <iostream>
#include <cstring>

bool is_palindrome(const char s[], int n) {
    int first = 0;
    int last = n - 1;
    while (first < last) {
        if (s[first] != s[last]) return false;
        ++first;
        --last;
    }
    return true;
}


std::istream &read_word(std::istream &is, char *buffer, int max) {
    is.width(max);
    is >> buffer;
    return is;
}

int main() {
    constexpr int max = 128;
    for (char s[max]; read_word(std::cin, s, max);) {
        std::cout << s << " is";
        if (!is_palindrome(s, strlen(s))) {
            std::cout << " not";
        }
        std::cout << " a palindrome";
    }
    return 0;
}
