//
// Created by Stefan Petrov on 20.08.25.
//

#ifndef STRIPED_RECTANGLE_H
#define STRIPED_RECTANGLE_H
#include "PPP/Graph.h"


class Striped_rectangle : public Graph_lib::Rectangle {
public:
    Striped_rectangle(Graph_lib::Point xy, int ww, int hh): Rectangle(xy, ww, hh) {
    };

    void draw_specifics(Graph_lib::Painter &painter) const override;
};


#endif //STRIPED_RECTANGLE_H
