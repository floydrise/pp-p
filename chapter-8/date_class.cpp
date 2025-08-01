#include <iostream>

enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec };

struct Year {
    int year;
};

class Date {
public:
    class Invalid {
    };

    Date() {
    };

    Date(Year y, Month m, int d);


    void add_day(int n);


    void set_day(const int val) {
        day = val;
    }

    bool is_valid();

    Month get_month() const { return month; };
    Year get_year() const { return year; };
    int get_day() const { return day; };

private:
    Year year = Year{2001};
    Month month = Month::jan;
    int day = 1;
};

Date::Date(const Year y, const Month m, const int d) : year{y}, month{m}, day{d} {
}

bool Date::is_valid() {
    if (const int m = static_cast<int>(month); m < 1 || m > 12) return false;
    if (day < 1 || day > 31) return false;
    return true;
}


void Date::add_day(int n) {
    day += n;
}

std::ostream &operator<<(std::ostream &os, const Date &d) {
    std::string month_str;
    Month m = d.get_month();
    switch (m) {
        case Month::jan:
            month_str = "January";
            break;
        case Month::feb:
            month_str = "February";
            break;
        case Month::mar:
            month_str = "March";
            break;
        case Month::apr:
            month_str = "April";
            break;
        case Month::may:
            month_str = "May";
            break;
        case Month::jun:
            month_str = "June";
            break;
        case Month::jul:
            month_str = "July";
            break;
        case Month::aug:
            month_str = "August";
            break;
        case Month::sept:
            month_str = "September";
            break;
        case Month::oct:
            month_str = "October";
            break;
        case Month::nov:
            month_str = "November";
            break;
        case Month::dec:
            month_str = "December";
            break;
        default:
            month_str = "No month";
            break;
    }
    return os << d.get_day() << "/" << month_str << "/" << d.get_year().year << std::endl;
}

int main() {
    const Date today{Year{2020}, Month::feb, 2};
    Date tomorrow = today;
    tomorrow.add_day(1);
    std::cout << "Today: " << today << std::endl;
    std::cout << "Tomorrow: " << tomorrow << std::endl;
    return 0;
}
