//
// Created by Stefan Petrov on 17.08.25.
//

#ifndef BOX_H
#define BOX_H
#include "Graph.h"


class Box : public Graph_lib::Shape {
public:
    Box(const Graph_lib::Point xy, const int ww, int hh, std::string str): rect(xy, ww, hh),
                                                                           label(Graph_lib::Point{
                                                                                   xy.x + 10,
                                                                                   xy.y + rect.height() / 2
                                                                               },
                                                                               str) {
    }

    void draw_specifics(Graph_lib::Painter &painter) const override {
        rect.draw_specifics(painter);
        label.draw_specifics(painter);
    };

private:
    Graph_lib::Rectangle rect;
    Graph_lib::Text label;
};


#endif //BOX_H
