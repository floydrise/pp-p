#include <iostream>

int main() {
    std::cout << "Hello, type your name and press 'Enter': " << std::endl;
    std::string first_name;
    std::cin >> first_name;
    std::cout << "Hello," << first_name << "!" << std::endl;
    return 0;
}
