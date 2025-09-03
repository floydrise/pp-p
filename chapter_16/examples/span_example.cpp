#include <iostream>
#include <span>

void print_span(const std::span<int> arr) {
    // modern C++ style iteration
    for (const int val: arr) {
        std::cout << val << " ";
    }
}

void print_ptr(const int *ptr, const int size) {
    // C style iteration, passing a pointer to array and size
    for (int i = 0; i < size; ++i) {
        std::cout << ptr[i] << " ";
    }
}

int main() {
    int arr[] = {1, 2, 3};
    print_span(std::span<int>{arr});
    std::cout << '\n';
    print_ptr(arr, std::size(arr));
    return 0;
}
