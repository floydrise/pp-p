#include <iostream>

int main() {
    // object declarations
    std::string first_name;
    std::string friend_name;
    int age = 0;

    std::cout << "Enter the name of the friend you want to write to: ";
    std::cin >> first_name;
    std::cout << "Dear " << first_name << ", \n\tHow are you?\n" << "I'm fine.\n" << "I miss you!" << std::endl;
    std::cout << "Enter another friend's name: ";
    std::cin >> friend_name;
    std::cout << "Have you seen " << friend_name << " lately?" << std::endl;
    std::cout << "Enter the age of the recipient: ";
    std::cin >> age;
    std::cout << "I hear you just had a birthday and you are " << age << " years old\n";

    if (age <= 0 || age >= 110) {
        std::cerr << ("error: Are you kidding?") << std::endl;
        return EXIT_FAILURE;
    }

    age <= 12
        ? std::cout << "Next year you'll be " << age + 1 << '\n'
        : age == 17
              ? std::cout << "Next year you'll be able to vote!\n"
              : age > 70
                    ? std::cout << "Are you retired?\n"
                    : std::cout << "";

    std::cout << "Yours sincerely," << "\n\n" << first_name << std::endl;
    return EXIT_SUCCESS;
}
