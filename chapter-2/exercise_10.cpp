// solution to exercise 10 from the book

#include <iostream>

int main() {
    std::string op;
    double num1, num2, result;
    std::cout << "Input operator and two operands separated with space: ";
    std::cin >> op >> num1 >> num2;

    if (op == "+" || op == "plus") {
        result = num1 + num2;
    } else if (op == "-" || op == "minus") {
        result = num1 - num2;
    } else if (op == "*" || op == "mul") {
        result = num1 * num2;
    } else if (op == "/" || op == "div") {
        result = num1 / num2;
    } else {
        result = 0;
    }

    std::cout << "Result: " << result << std::endl;
    return EXIT_SUCCESS;
}
