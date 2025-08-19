#include "B1.h"
#include <iostream>

using namespace Drill;

void B1::vf() {
    std::cout << "B1::vf()\n";
}

void B1::f() {
    std::cout << "B1::f()\n";
}

void B1::pvf() {
    std::cout << "B1::pvf()\n";
}


void D1::vf() {
    std::cout << "D1::vf()\n";
}

void D1::f() {
    std::cout << "D1::f()\n";
}

void D2::pvf() {
    std::cout << "D2::pvf()\n";
}

void B2::vpf() {
    std::cout << "B2::vpf()\n";
}

void D21::vpf() {
    std::cout << str << '\n';
}

void D22::vpf() {
    std::cout << num << '\n';
}
