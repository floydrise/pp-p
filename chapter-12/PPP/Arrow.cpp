//
// Created by Stefan Petrov on 17.08.25.
//


#include "Arrow.h"

#include <cmath>

#include "Window.h"

void Arrow::draw_specifics(Graph_lib::Painter &painter) const {
    // draw main shaft
    painter.draw_line(point(0), point(1));
    Graph_lib::Point tail = point(0);
    Graph_lib::Point tip = point(1);
    if (tail.x == tip.x && tail.y == tip.y) throw std::runtime_error("Arrow endpoints must not be identical");

    // direction vector
    const double dir_vec_x = tip.x - tail.x;
    const double dir_vec_y = tip.y - tail.y;

    // unit vector
    const double length = sqrt(dir_vec_x * dir_vec_x + dir_vec_y * dir_vec_y);
    const double unit_vec_x = dir_vec_x / length;
    const double unit_vec_y = dir_vec_y / length;

    // perpendicular vector
    const double perp_vec_x = -unit_vec_y;
    const double perp_vec_y = unit_vec_x;

    // arrowhead params
    constexpr int arrow_height = 15;
    constexpr int arrow_width = 7;

    // corner points
    const Graph_lib::Point corner_pt_1{
        static_cast<int>(std::lround(tip.x - arrow_height * unit_vec_x + arrow_width * perp_vec_x)),
        static_cast<int>(std::lround(tip.y - arrow_height * unit_vec_y + arrow_width * perp_vec_y))
    };
    const Graph_lib::Point corner_pt_2{
        static_cast<int>(std::lround(tip.x - arrow_height * unit_vec_x - arrow_width * perp_vec_x)),
        static_cast<int>(std::lround(tip.y - arrow_height * unit_vec_y - arrow_width * perp_vec_y))
    };

    // draw arrowhead
    painter.draw_line(tip, corner_pt_1);
    painter.draw_line(tip, corner_pt_2);
}
