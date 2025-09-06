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

Vector::Vector(const Vector &arg): sz(arg.sz), elem(new double[arg.sz]) {
    std::copy_n(arg.elem, sz, elem);
}

Vector &Vector::operator=(const Vector &arg) {
    if (this == &arg) return *this;

    auto *p = new double[arg.sz];
    std::copy_n(arg.elem, sz, p);
    delete[] elem;
    elem = p;
    sz = arg.sz;
    return *this;
}

Vector::Vector(Vector &&arg) noexcept : sz{arg.sz}, elem{arg.elem} {
    arg.sz = 0;
    arg.elem = nullptr;
}

Vector &Vector::operator=(Vector &&arg) noexcept {
    if (this != &arg) {
        delete[] elem;
        elem = arg.elem;
        sz = arg.sz;
        arg.elem = nullptr;
        arg.sz = 0;
    }
    return *this;
}
