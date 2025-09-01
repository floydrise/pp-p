//
// Created by Stefan Petrov on 30.08.25.
//

#ifndef VECTOR_H
#define VECTOR_H


class Vector {
public:
    explicit Vector(int s);

    ~Vector() { delete[] elem; };

    int size() const { return sz; };
    int get(const int n) const { return elem[n]; };
    void set(const int n, const int v) const { elem[n] = v; };

private:
    int sz = 0;
    double *elem = nullptr;
};


#endif //VECTOR_H
