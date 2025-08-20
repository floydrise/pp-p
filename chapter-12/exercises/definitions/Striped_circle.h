//
// Created by Stefan Petrov on 20.08.25.
//

#ifndef STRIPED_CIRCLE_H
#define STRIPED_CIRCLE_H
#include "PPP/Graph.h"


class Striped_circle : public Graph_lib::Circle {
public:
    Striped_circle(Graph_lib::Point p, int rr): Circle(p, rr) {
    };

    void draw_specifics(Graph_lib::Painter &painter) const override;
};


#endif //STRIPED_CIRCLE_H
