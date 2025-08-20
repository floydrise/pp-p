#include "Striped_rectangle.h"

#include "PPP/Window.h"

void Striped_rectangle::draw_specifics(Graph_lib::Painter &painter) const {
    Rectangle::draw_specifics(painter);

    Graph_lib::Point nw = point(0);
    Graph_lib::Point ne = north_east();
    Graph_lib::Point se = south_east();

    for (int y = nw.y + 10; y < se.y; y += 10) {
        painter.draw_line({nw.x, y}, {ne.x, y});
    }
}
