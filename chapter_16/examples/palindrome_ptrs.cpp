// when I tried this it only compiled using C++17, not C++23
#include <iostream>
#include <cstring>

using namespace std;

bool is_palindrome(const char *first, const char *last) {
    if (first < last)
        return (*first == *last) ? is_palindrome(first + 1, last - 1) : false;
    return true;
}

std::istream &read_word(std::istream &is, char *buffer, int max) {
    is.get(buffer, max, ' ');
    is.ignore();
    return is;
}


int main() {
    constexpr int max = 128;
    for (char s[max]; read_word(cin, s, max);) {
        cout << s << " is";
        if (!is_palindrome(&s[0], &s[strlen(s) - 1]))
            cout << " not";
        cout << " a palindrome\n";
    }
}
