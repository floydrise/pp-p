//
// Created by Stefan Petrov on 30.08.25.
//

#include "./Vector.h"

#include <__bit_reference>

Vector::Vector(const int s): sz(s), elem(new double[s]) {
    for (int i = 0; i < s; ++i) {
        elem[i] = 0;
    }
}

Vector::Vector(const std::initializer_list<double> lst): sz(lst.size()), elem(new double[sz]) {
    std::copy(lst.begin(), lst.end(), elem);
}
