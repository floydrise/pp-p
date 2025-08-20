//
// Created by Stefan Petrov on 20.08.25.
//

#ifndef IMMOBILE_CIRCLE_H
#define IMMOBILE_CIRCLE_H
#include "PPP/Graph.h"


class Immobile_circle : public Graph_lib::Circle {
public:
    Immobile_circle(Graph_lib::Point p, int rr) : Circle(p, rr) {
    }

private:
    void move(int, int) override {
    };
};


#endif //IMMOBILE_CIRCLE_H
