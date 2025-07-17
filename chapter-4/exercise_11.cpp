#include <iostream>

/*
 “Write a program that writes out the first N values of the Fibonacci series, that is, the series that starts with
 0 1 1 2 3 5 8 13 21 34. The next number of the series is the sum of the two previous ones. Find the largest Fibonacci number that fits in an int.”
*/

int fibonacci(int n) {
    // first solution used this fn, but was slow and was overflowing (skill issue 🤣)
    if (n < 0) throw std::invalid_argument("Invalid argument for 'n'. Should be > 0");
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main() {
    int a = 0;
    int b = 1;
    int next = 0;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    while (true) {
        if (b > INT_MAX - a) {
            break;
        }
        next = a + b;
        std::cout << next << std::endl;
        a = b;
        b = next;
    }
    return 0;
}
