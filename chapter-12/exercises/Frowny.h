#ifndef FROWNY_H
#define FROWNY_H
#include "PPP/Graph.h"


class Frowny : public Graph_lib::Circle {
public:
    Frowny(Graph_lib::Point p, int rr): Circle(p, rr) {
    };

    void draw_specifics(Graph_lib::Painter &painter) const override;
};


#endif //FROWNY_H
