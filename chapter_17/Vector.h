//
// Created by Stefan Petrov on 30.08.25.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>


class Vector {
public:
    explicit Vector(int s); // constructor

    Vector(std::initializer_list<double> lst); // list initialisation

    Vector(const Vector &); // copy constructor

    Vector &operator=(const Vector &); // copy assignment

    Vector(Vector &&) noexcept; // move constructor

    Vector &operator=(Vector &&) noexcept; // move assignment

    ~Vector() { delete[] elem; }; // move destructor

    [[nodiscard]] int size() const { return sz; };
    double &operator[](const int n) { return elem[n]; };
    const double &operator[](const int n) const { return elem[n]; };

    // not needed now we have operator[]
    [[nodiscard]] double get(const int n) const { return elem[n]; };
    void set(const int n, const int v) const { elem[n] = v; };

private:
    int sz = 0;
    double *elem = nullptr;
};


#endif //VECTOR_H
