//
// Created by Stefan Petrov on 4.08.25.
//

#include <iostream>

void print(const std::string &label, const std::pmr::vector<int> &int_arr) {
    std::cout << label << std::endl;
    for (int i = 0; i < int_arr.size(); ++i) {
        std::cout << int_arr[i] << (i == int_arr.size() - 1 ? "\n" : ", ");
    }
}

void fibonacci(int x, int y, std::pmr::vector<int> &v, int n) {
    int first = x;
    int second = y;
    int next = 0;
    v.insert(v.end(), {x, y});
    while (v.size() < n) {
        next = first + second;
        v.push_back(next);
        first = second;
        second = next;
    }
}

int main() {
    std::pmr::vector<int> my_vector;
    fibonacci(1, 2, my_vector, 10);
    print("Fibonacci:", my_vector);
    return 0;
}
