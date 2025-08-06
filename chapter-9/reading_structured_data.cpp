//
// Created by Stefan Petrov on 6.08.25.
//


#include <fstream>
#include <iostream>
#include <vector>

constexpr int not_a_reading = -7777;
constexpr int not_a_month = -1;
constexpr int implausible_min = -200;
constexpr int implausible_max = 200;


struct Day {
    std::vector<double> temp = std::vector<double>(24, not_a_reading);
};

struct Month {
    int month = not_a_month;
    std::vector<Day> day = std::vector<Day>(32);
};

struct Year {
    int year;
    std::vector<Month> month = std::vector<Month>(12);
};

struct Reading {
    int day;
    int hour;
    double temperature;
};

std::vector<std::string> month_input_tbl = {
    "-not a month-", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};

std::vector<std::string> month_print_tbl{
    "-not a month-", " January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
    "November", "December”
};

bool is_valid(const Reading &r)
// a rough test
{
    if (r.day < 1 || 31 < r.day)
        return false;
    if (r.hour < 0 || 23 < r.hour)
        return false;
    if (r.temperature < implausible_min || implausible_max < r.temperature)
        return false;
    return true;
}

void end_of_loop(std::istream &ist, const char term, const std::string &message) {
    if (ist.fail()) {
        // use term as terminator and/or separator
        ist.clear();
        if (char ch = 0; ist >> ch && ch == term)
            return; // all is fine
        throw std::runtime_error(message);
    }
}

int month_to_int(const std::string &s) {
    for (int i = 1; i < 13; ++i) {
        if (month_input_tbl[i] == s) return i;
    }
    return 0;
}

std::string int_to_month(const int i) {
    if (i < 1 || i >= 12) throw std::invalid_argument("Bad month index");
    return month_print_tbl[i];
}

std::istream &operator>>(std::istream &is, Reading &reading) {
    if (char ch1; is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(std::ios::failbit);
        return is;
    }
    if (char ch2; (is >> reading.day >> reading.hour >> reading.temperature >> ch2) && ch2 != ')') {
        throw std::invalid_argument("Invalid reading");
    }
    return is;
}

std::istream &operator>>(std::istream &is, Month &m) {
    if (char ch = 0; is >> ch && ch != '{') {
        is.unget();
        is.clear(std::ios::failbit);
        return is;
    }

    std::string month_marker;
    std::string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month") {
        throw std::invalid_argument("bad start of month");
    }
    m.month = month_to_int(mm);

    int duplicates = 0;
    int invalids = 0;

    for (Reading r; is >> r;) {
        if (is_valid(r)) {
            if (m.day[r.day].temp[r.temperature] != not_a_reading)
                ++duplicates;
            m.day[r.day].temp[r.temperature] = r.temperature;
        } else {
            ++invalids;
        }
    }
    if (invalids) throw std::runtime_error("Invalid readings in month");
    if (duplicates) throw std::runtime_error("Invalid readings in duplicates");
    end_of_loop(is, '}', "bad end of month");
    return is;
}

std::istream &operator>>(std::istream &is, Year &y) {
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        is.clear(std::ios::failbit);
        return is;
    }

    std::string year_marker;
    int yy = -1;

    is >> year_marker >> yy;
    if (!is || year_marker != "year") {
        throw std::invalid_argument("bad start of year");
    }
    y.year = yy;

    while (true) {
        Month m;
        if (!(is >> m))
            break;
        y.month[m.month] = m;
    }
    end_of_loop(is, '}', "Bad end of year");
    return is;
};

void print_year(std::ofstream &ofs, Year &y);

int main() try {
    std::cout << "Please enter input file name\n";
    std::string iname;
    std::cin >> iname;
    std::ifstream ifs{iname};
    if (!ifs)
        throw std::runtime_error("can't open input file");

    ifs.exceptions(ifs.exceptions() | std::ios::badbit); // throw for bad()

    // open an output file:
    std::cout << "Please enter output file name\n";
    std::string oname;
    std::cin >> oname;
    std::ofstream ofs{oname};
    if (!ofs)
        throw std::runtime_error("can't open output file");

    // read an arbitrary number of years:
    std::vector<Year> ys;
    while (true) {
        Year y; // get a freshly initialized Year each time around
        if (!(ifs >> y))
            break;
        ys.push_back(y);
    }
    std::cout << "read " << ys.size() << " years of readings\n";

    for (Year &y: ys)
        print_year(ofs, y);
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
}
