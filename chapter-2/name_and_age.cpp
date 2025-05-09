#include <iostream>

int main() {
    std::cout << "Type your name and age separated with space and hit 'Enter': " << std::endl;
    std::string user_name;
    int age = 0;
    std::cin >> user_name >> age;
    std::cout << "Hi " << user_name << " aged " << age << std::endl;
    return EXIT_SUCCESS;
}
