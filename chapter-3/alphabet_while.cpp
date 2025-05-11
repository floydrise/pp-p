#include <iostream>

int main() {
    int counter = 0;
    while (counter < 26) {
        std::cout << static_cast<char>('a' + counter) << '\t' << static_cast<int>('a' + counter) << '\n';
        counter++;
    }
    return EXIT_SUCCESS;
}
