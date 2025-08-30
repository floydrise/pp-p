//
// Created by Stefan Petrov on 30.08.25.
//

#ifndef VECTOR_H
#define VECTOR_H


class Vector {
    int sz = 0;
    double *elem = nullptr;

public:
    Vector(int s): sz(s) {
    };
    int size() { return sz; };
};


#endif //VECTOR_H
