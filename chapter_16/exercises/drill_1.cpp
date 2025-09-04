#include <iostream>
#include <print>
int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(const int *arr, const int n) {
    int la[10];
    std::cout << "la values: ";
    for (int i = 0; i < n; ++i) {
        la[i] = arr[i];
        std::print("{} ", la[i]);
        if (i == 9) std::cout << '\n';
    }
    int *p = new int[10];
    std::cout << "*p values: ";
    for (int i = 0; i < n; ++i) {
        p[i] = arr[i];
        std::print("{} ", p[i]);
        if (i == 9) std::cout << '\n';
    }
    delete[] p;
};

int factorial(int n) {
    if (n == 0) return 1;
    int ret_val = 1;
    while (n > 0) {
        ret_val *= n;
        --n;
    }
    return ret_val;
}

int main() {
    f(ga, 10);
    int aa[10];
    for (int i = 0; i < 10; ++i) {
        aa[i] = factorial(i + 1);
    }
    f(aa, 10);
}
