#include <iostream>

void print_array(std::ostream &os, const int *a, const int n) {
    for (int i = 0; i < n; ++i) {
        os << a[i] << std::endl;
    }
}

int main() {
    int num = 7;
    int *p1 = &num;
    std::cout << "Value of num: " << num << '\n' << "Value of p1: " << *p1 << std::endl;


    int *num_arr = new int[10];
    for (int i = 0; i < 10; ++i) {
        num_arr[i] = i;
    }
    int *p2 = num_arr;
    for (int i = 0; i < 10; ++i) {
        std::cout << p2[i];
        if (i < 9) std::cout << ", ";
        if (i == 9) std::cout << std::endl;
    }

    int *p3 = p2;
    p2 = p1;
    p2 = p3;

    std::cout << "Value of *p1: " << *p1 << " Value of *p2: " << *p2 << std::endl;

    int *arr2 = new int[10];
    for (int i = 0; i < 10; ++i) {
        arr2[i] = i;
    }
    p1 = arr2;
    int *arr3 = new int[10];
    p2 = arr3;

    for (int i = 0; i < 10; ++i) {
        p2[i] = p1[i];
        std::cout << p2[i] << " ";
    }

    delete[] num_arr;
    delete[] arr2;
    delete[] arr3;
}
