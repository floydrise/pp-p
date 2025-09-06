#include <iostream>

#include "Vector.h"

int main() {
    Vector v(10);
    for (int i = 0; i < 10; ++i) {
        v[i] = i;
        std::cout << v[i] << std::endl;
    }
    return 0;
}
