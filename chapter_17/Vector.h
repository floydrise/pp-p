//
// Created by Stefan Petrov on 30.08.25.
//

#ifndef VECTOR_H
#define VECTOR_H


class Vector {
public:
    explicit Vector(int s);

    ~Vector() { delete[] elem; };

    [[nodiscard]] int size() const { return sz; };
    [[nodiscard]] double get(const int n) const { return elem[n]; };
    void set(const int n, const int v) const { elem[n] = v; };
    double &operator[](const int n) { return elem[n]; };
    const double &operator[](const int n) const { return elem[n]; };

private:
    int sz = 0;
    double *elem = nullptr;
};


#endif //VECTOR_H
