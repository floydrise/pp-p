// using C++23 -> std::print() instead of std::cout

#include <iostream>
int fac_recursive(const int x) { return x > 1 ? x * fac_recursive(x - 1) : 1; };

int fac_iterative(int x) {
    int ret_val = 1;
    while (x > 1) {
        ret_val *= x;
        --x;
    }
    return ret_val;
};

int main() {
    int recursive = fac_recursive(4);
    int iterative = fac_iterative(4);
    std::print("Iterative: {}\nIterative: {}\n", iterative, recursive);
    return 0;
};
