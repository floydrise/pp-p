//
// Created by Stefan Petrov on 4.08.25.
//

#include <iostream>
#include <string>
#include <vector>

void print(const std::string &label, const std::pmr::vector<int> &int_arr) {
    std::cout << label << std::endl;
    for (int i = 0; i < int_arr.size(); ++i) {
        std::cout << int_arr[i] << (i == int_arr.size() - 1 ? "\n" : ", ");
    }
}

int main() {
    const std::pmr::vector int_arr{1, 2, 3, 4, 5};
    print("Int array:", int_arr);
    return 0;
}
