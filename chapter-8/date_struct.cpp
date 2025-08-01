#include <iostream>

struct Date {
    int year;
    int month;
    int day;

    Date(int year, int month, int day);

    void print_date() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    };
};

Date::Date(const int year, const int month, const int day): year(year), month(month), day(day) {
}


int main() {
    Date today{2025, 12, 24};
    today.print_date();
    return 0;
}
