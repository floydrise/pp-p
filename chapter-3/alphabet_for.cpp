#include <iostream>

int main() {
    for (int i = 0; i < 26; ++i) {
        std::cout << static_cast<char>('A' + i) << '\t' << static_cast<int>('A' + i) << '\n';
        std::cout << static_cast<char>('a' + i) << '\t' << static_cast<int>('a' + i) << '\n';
    }
    return EXIT_SUCCESS;
}
