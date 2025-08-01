#include <iosfwd>
#include <iostream>

enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec };

Month operator++(Month &m) {
    m = m == Month::dec ? Month::jan : Month{static_cast<int>(m) + 1};
    return m;
}

std::ostream &operator<<(std::ostream &os, const Month m) {
    switch (m) {
        case Month::jan: os << "January";
            break;
        case Month::feb: os << "February";
            break;
        case Month::mar: os << "March";
            break;
        case Month::apr: os << "April";
            break;
        case Month::may: os << "May";
            break;
        case Month::jun: os << "June";
            break;
        case Month::jul: os << "July";
            break;
        case Month::aug: os << "August";
            break;
        case Month::sept: os << "September";
            break;
        case Month::oct: os << "October";
            break;
        case Month::nov: os << "November";
            break;
        case Month::dec: os << "December";
            break;
        default: os << "Unknown";
            break;
    }
    return os;
}

int main() {
    auto m1 = Month::jan;
    std::cout << m1 << std::endl;
    ++m1;
    std::cout << m1 << std::endl;
}
