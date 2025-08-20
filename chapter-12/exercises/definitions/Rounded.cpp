//
// Created by Stefan Petrov on 20.08.25.
//

#include "Rounded.h"

#include "PPP/Window.h"

void Rounded::draw_specifics(Graph_lib::Painter &painter) const {
    constexpr int r = 10;
    const auto [x, y] = point(0);
    constexpr int diameter = 2 * r;

    // top left
    const Graph_lib::Point arc_box_top_left{x + diameter, y + diameter};
    const Graph_lib::Arc top_left_arc{arc_box_top_left, diameter, diameter, 90, 90};

    // top right
    const Graph_lib::Point arc_box_top_right{(x + w) - diameter, y + diameter};
    const Graph_lib::Arc top_right_arc{arc_box_top_right, diameter, diameter, 0, 90};

    // bottom right
    const Graph_lib::Point arc_box_bottom_right{x + w - 2 * r, y + h - 2 * r};
    const Graph_lib::Arc bottom_right_arc{arc_box_bottom_right, diameter, diameter, 270, 90};

    // bottom left
    const Graph_lib::Point arc_box_bottom_left{x + diameter, y + h - diameter};
    const Graph_lib::Arc bottom_left_arc{arc_box_bottom_left, diameter, diameter, 180, 90};

    // connecting lines
    Graph_lib::Line top_line{{x + r + 8, y}, {x + w - r - 8, y}};
    Graph_lib::Line right_line{{x + w, y + r + 8}, {x + w, y + h - r - 8}};
    Graph_lib::Line bottom_line{{x + r + 8, y + h}, {x + w - r - 8, y + h}};
    Graph_lib::Line left_line{{x, y + r + 8}, {x, y + h - r - 8}};

    // draw
    top_left_arc.draw_specifics(painter);
    top_right_arc.draw_specifics(painter);
    bottom_right_arc.draw_specifics(painter);
    bottom_left_arc.draw_specifics(painter);
    top_line.draw_specifics(painter);
    right_line.draw_specifics(painter);
    bottom_line.draw_specifics(painter);
    left_line.draw_specifics(painter);
}
