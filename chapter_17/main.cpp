#include <iostream>

#include "Vector.h"

int main() {
    Vector v{1, 2, 3};
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}
