#ifndef SMILEY_H
#define SMILEY_H
#include "PPP/Graph.h"


class Smiley : public Graph_lib::Circle {
public:
    Smiley(const Graph_lib::Point p, const int rr)
        : Circle(p, rr) {
    }

    void draw_specifics(Graph_lib::Painter &painter) const override;
};


#endif //SMILEY_H
