#include <iostream>

int main() {
    char *ch_arr = new char[10];
    int index = 0;
    while (true) {
        std::cout << "Write a char: ";
        std::cin >> ch_arr[index];

        if (ch_arr[index] == '!') break;
        ++index;
        if (index >= 10) {
            std::cout << "Out of bands, exiting loop\n";
            break;
        }
    }
    std::cout << "Array values:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << ch_arr[i] << " ";
    }
    delete[] ch_arr;
}
