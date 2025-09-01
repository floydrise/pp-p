//
// Created by Stefan Petrov on 30.08.25.
//

#include "Vector.h"

Vector::Vector(const int s): sz(s), elem(new double[s]) {
    for (int i = 0; i < s; ++i) {
        elem[i] = 0;
    }
}

Vector::~Vector() {
    delete[] elem;
}
