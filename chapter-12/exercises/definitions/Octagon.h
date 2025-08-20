//
// Created by Stefan Petrov on 20.08.25.
//

#ifndef OCTAGON_H
#define OCTAGON_H
#include "PPP/Graph.h"


class Octagon : public Graph_lib::Shape {
public:
    Octagon(Graph_lib::Point center, const int len): side_length(len) {
        if (len <= 0) throw runtime_error("Length can't be less than or equal to 0");

        const double r = radius();
        for (int i = 0; i < 8; ++i) {
            constexpr int starting_angle = -90;
            const double angle_rad = (starting_angle + i * 45) * M_PI / 180.0;
            const int x = center.x + static_cast<int>(r * cos(angle_rad) + 0.5);
            const int y = center.y + static_cast<int>(r * sin(angle_rad) + 0.5);
            add(Graph_lib::Point{x, y});
        }
    };

    void draw_specifics(Graph_lib::Painter &) const override;

    int length() const { return side_length; };
    int radius() const { return side_length * sqrt(1 + 1 / sqrt(2)); };

private:
    int side_length = 0;
};


#endif //OCTAGON_H
