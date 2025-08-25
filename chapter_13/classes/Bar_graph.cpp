//
// Created by Stefan Petrov on 25.08.25.
//

#include "Bar_graph.h"

void Bar_graph::draw_specifics(Graph_lib::Painter &painter) const {
    const int bar_width = 40;
    const int spacing = 10;

    for (size_t i = 0; i < values.size(); ++i) {
        int x = point(0).x + i * (bar_width + spacing);
        int y = point(0).y - static_cast<int>(values[i]); // bars grow upward
        Graph_lib::Rectangle bar{{x, y}, bar_width, static_cast<int>(values[i])};
        bar.draw(painter);
    }
}
