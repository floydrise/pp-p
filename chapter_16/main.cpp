#include <iostream>
#include <print>
#include <vector>

std::vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(const std::vector<int> &v) {
    std::vector<int> lv(10);
    for (int i = 0; i < lv.size(); ++i) {
        lv[i] = v[i];
        std::print("{} ", lv[i]);
        if (i == 9) std::cout << '\n';
    }
    std::vector<int> lv2 = v;
    for (int i = 0; i < lv2.size(); ++i) {
        std::print("{} ", lv2[i]);
        if (i == 9) std::cout << '\n';
    }
}

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
    f(gv);
    std::vector<int> vv(10);
    for (int i = 0; i < 10; ++i) {
        vv[i] = factorial(i + 1);
    }
    f(vv);
}
