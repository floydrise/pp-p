#include <iostream>

bool is_palindrome(const std::string &str) {
    int first = 0;
    int last = str.length() - 1;
    while (first < last) {
        if (std::tolower(str[last]) != std::tolower(str[first]))
            return false;
        ++first;
        --last;
    }
    return true;
}

int main() {
    std::string str = "Anna";
    std::cout << (is_palindrome(str) ? "true" : "false") << std::endl;
    return 0;
}
