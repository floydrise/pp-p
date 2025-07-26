//
// Created by Stefan Petrov on 26.07.25.
//
#include <iostream>

int main() {
    int res = 1;
    for (int i = 7; i >= 1; --i) {
        res *= i;
    }
    std::cout << typeid(res).name() << std::endl;
    return 0;
}
