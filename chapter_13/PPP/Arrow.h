//
// Created by Stefan Petrov on 17.08.25.
//

#ifndef ARROW_H
#define ARROW_H
#include "Graph.h"


class Arrow : public Graph_lib::Shape {
public:
    Arrow(Graph_lib::Point a, Graph_lib::Point b) {
        add(a);
        add(b);
    }

    void draw_specifics(Graph_lib::Painter &painter) const override;
};


#endif //ARROW_H
