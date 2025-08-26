//
// Created by Stefan Petrov on 17.08.25.
//

#ifndef BOX_H
#define BOX_H
#include "Graph.h"


struct Box : Graph_lib::Shape {
    Graph_lib::Rectangle rect;
    Graph_lib::Text label;

    Box(const Graph_lib::Point xy, const int ww, int hh, std::string str): rect(xy, ww, hh),
                                                                           label(Graph_lib::Point{
                                                                                   xy.x + 10,
                                                                                   xy.y + 10
                                                                               },
                                                                               str) {
    }

    void draw_specifics(Graph_lib::Painter &painter) const override {
        rect.draw_specifics(painter);
        label.draw_specifics(painter);
    };
};


#endif //BOX_H
