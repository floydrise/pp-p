#ifndef ROUNDED_H
#define ROUNDED_H
#include "PPP/Graph.h"


class Rounded : public Graph_lib::Shape {
public:
    Rounded(Graph_lib::Point xy, int ww, int hh) : w(ww), h(hh) {
        if (h <= 0 || w <= 0) error("Bad rectangle: non-positive side");
        add(xy);
    }

    void draw_specifics(Graph_lib::Painter &painter) const override;

    int width() const { return w; };
    int height() const { return h; };

private:
    int w = 0; // width
    int h = 0; // height
};


#endif //ROUNDED_H
