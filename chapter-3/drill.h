//
// Created by Stefan Petrov on 11.05.25.
//

#ifndef DRILL_H
#define DRILL_H
#include <string>

inline double to_meters(const double digit, const std::string &unit) {
    double ret_val = 0;
    if (unit == "m") return digit;
    if (unit == "cm") ret_val = digit / 100;
    if (unit == "in") ret_val = digit / 39.37;
    if (unit == "ft") ret_val = digit / 3.281;
    return ret_val;
}

#endif //DRILL_H
