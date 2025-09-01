//
// Created by Stefan Petrov on 30.08.25.
//

#ifndef VECTOR_H
#define VECTOR_H


class Vector {
public:
    explicit Vector(int s);

    ~Vector();

    int size() const { return sz; };

private:
    int sz = 0;
    double *elem = nullptr;
};


#endif //VECTOR_H
