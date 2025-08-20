//
// Created by Stefan Petrov on 20.08.25.
//

#include "Octagon.h"

#include "PPP/Window.h"

void Octagon::draw_specifics(Graph_lib::Painter &painter) const {
    for (int i = 0; i < number_of_points(); ++i) {
        Graph_lib::Point p1 = point(i);
        Graph_lib::Point p2 = point((i + 1) % number_of_points()); // wrap around to first
        painter.draw_line(p1, p2);
    }
}
