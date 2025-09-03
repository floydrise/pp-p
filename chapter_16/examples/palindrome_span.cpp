// this does not compile using C++17/23/26 using clang++
#include <iostream>
#include <span>

using namespace std;

bool is_palindrome(span<char> s) {
    if (s.size() < 2)
        return true;
    return (s.front() == s.back()) ? is_palindrome(span<int>{s.data() + 1, s.size() - 2}) : false;
}

std::istream &read_word(std::istream &is, char *buffer, int max) {
    is.width(max);
    is >> buffer;
    return is;
}


int main() {
    constexpr int max = 128;
    for (char s[max]; read_word(cin, s, max);) {
        cout << s << " is";
        if (!is_palindrome(span<char>{s}))
            cout << " not";
        cout << " a palindrome\n";
    }
}
