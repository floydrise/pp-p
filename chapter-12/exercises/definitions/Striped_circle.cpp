//
// Created by Stefan Petrov on 20.08.25.
//

#include "Striped_circle.h"

#include <valarray>

#include "PPP/Window.h"

void Striped_circle::draw_specifics(Graph_lib::Painter &painter) const {
    Circle::draw_specifics(painter);


    Graph_lib::Point c = center();
    int r = radius();

    for (int y = c.y - r; y <= c.y + r; y += 10) {
        int dy = y - c.y;
        int dx_sq = r * r - dy * dy;
        if (dx_sq < 0) continue;

        int dx = static_cast<int>(std::sqrt(dx_sq));

        painter.draw_line({c.x - dx, y}, {c.x + dx, y});
    }
}
