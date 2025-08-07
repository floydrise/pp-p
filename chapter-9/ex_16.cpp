// Write a program that produces the sum of all the numbers in a file of whitespace-separated integers.

#include <iostream>
#include <fstream>

int main() {
    int sum = 0;
    int buffer = 0;
    std::ifstream ifs{"whitespace_integers.txt"};
    while (ifs >> buffer) {
        sum += buffer;
    }
    std::cout << sum << '\n';
    return 0;
}
