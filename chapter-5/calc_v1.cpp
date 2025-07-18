#include <iostream>

int main() {
    int lval, rval, sum = 0;
    char op;
    std::cout << "Expression: " << std::endl;
    std::cin >> lval >> op >> rval;
    switch (op) {
        case '+':
            sum = rval + lval;
            break;
        case '-':
            sum = lval - rval;
            break;
        case '*':
            sum = lval * rval;
            break;
        case '/':
            sum = lval / rval;
            break;
        default:
            std::cerr << "Can't evaluate";
            break;
    }
    std::cout << sum << std::endl;
    return 0;
}
