#include <iostream>

double to_meters(const double digit, const std::string &unit) {
    double ret_val = 0;
    if (unit == "m") return digit;
    if (unit == "cm") ret_val = digit / 100;
    if (unit == "in") ret_val = digit / 39.37;
    if (unit == "ft") ret_val = digit / 3.281;
    return ret_val;
}

int main() {
    bool terminate = false;
    double sum = 0;
    std::vector<double> values;
    while (!terminate) {
        char inp;
        std::string unit;
        double num;
        std::cout << "Input a digit and a unit (cm, in, ft, m) separated with a space: ";
        std::cin >> num >> unit;
        if (unit != "cm" && unit != "in" && unit != "ft" && unit != "m") {
            std::cout << "Unrecognised unit!\n";
            continue;
        }
        std::cout << "You entered: " << num << unit << '\n';
        num = to_meters(num, unit);
        values.push_back(num);
        sum += num;
        std::cout << "Do you wanna exit (y/n)? ";
        std::cin >> inp;
        std::cout << std::endl;
        if (inp == 'y') {
            terminate = true;
            std::cout << "\nExited the loop" << '\n';
        }
    }
    std::sort(values.begin(), values.end());
    std::cout << "You entered the fallowing values in meters: ";
    for (const double value: values) {
        std::cout << value << "m, ";
    }
    std::cout << "\nSmallest value in meters: " << values[0] << "m" << '\n';
    std::cout << "Largest value in meters: " << values[values.size() - 1] << "m" << '\n';
    std::cout << "Sum of all values: " << sum << "m" << '\n';
    return 0;
}
