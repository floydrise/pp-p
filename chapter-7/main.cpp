#include <iostream>

int main() {
    std::string str;
    std::vector<std::string> arr;
    while (std::cin >> str) {
        if (str == "quit") break;
        arr.push_back(str);
    }
    for (const auto &value: arr) {
        std::cout << value << std::endl;
    }
    return 0;
}
