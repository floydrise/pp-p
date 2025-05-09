// Included two possible solutions
// First one is better, but uses methods not yet covered by the book (can easily be googled)

#include <iostream>

int main() {
    std::array<int, 3> my_arr{};
    std::cout << "Write three integers: ";
    std::cin >> my_arr[0] >> my_arr[1] >> my_arr[2];
    std::sort(my_arr.begin(), my_arr.end());
    std::cout << my_arr[0] << ", " << my_arr[1] << ", " << my_arr[2] << std::endl;
    return EXIT_SUCCESS;
}

/*
#include <cstdlib>
#include <iostream>
int main() {
    int a = 0, b = 0, c = 0;
    std::cout << "Write three integers: ";
    std::cin >> a >> b >> c;
    int min = a, max = 0, mid = 0;

    if (min > a) {
        min = a;
    }
    if (min > b) {
        min = b;
    }
    if (min > c) {
        min = c;
    }

    if (max < a) {
        max = a;
    }
    if (max < b) {
        max = b;
    }
    if (max < c) {
        max = c;
    }

    mid = (a + b + c) - (min + max);

    std::cout << min << ", " << mid << ", " << max << std::endl;

    return EXIT_SUCCESS;
}
*/
