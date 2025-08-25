#include <complex>
#include <iostream>

#include "classes/Fct.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

double dsin(const double x) { return sin(x); };
double dcos(const double x) { return cos(x); };

int main() {
    constexpr int win_w = 600, win_h = 600;

    constexpr int x_mid = win_w / 2;
    constexpr int y_mid = win_h / 2;

    constexpr int axis_len = 400;

    constexpr int x_scale = 20, y_scale = 20;

    constexpr int padding = 100; // 100px left, right, top and bottom with axis length 400 and win h&w 600

    constexpr int range_min = -10;
    constexpr int range_max = 11;

    constexpr Point orig{x_mid, y_mid};
    constexpr int count = 400;

    Application app;
    Simple_window window{{400, 200}, win_w, win_h, "Function graphs"};

    Axis xa{Axis::x, {padding, y_mid}, axis_len, axis_len / x_scale, "1 == 20 pixels"};
    Axis ya{Axis::y, {x_mid, win_h - padding}, axis_len, axis_len / y_scale, "1 == 20 pixels"};

    Function f1{dsin, range_min, range_max, orig, count, x_scale, y_scale}; // blue
    Function f2{dcos, range_min, range_max, orig, count, x_scale, y_scale}; // red
    Function f3{
        [](const double x) -> double { return sin(x) + cos(x); }, range_min, range_max, orig, count, x_scale, y_scale
    }; // green
    Function f4{
        [](const double x) -> double { return (sin(x) * sin(x)) + (cos(x) * cos(x)); }, range_min, range_max, orig,
        count, x_scale, y_scale
    }; // yellow

    f1.set_color(Color::blue);
    f2.set_color(Color::red);
    f3.set_color(Color::green);
    f4.set_color(Color::yellow);

    window.attach(xa);
    window.attach(ya);
    window.attach(f1);
    window.attach(f2);
    window.attach(f3);
    window.attach(f4);

    app.gui_main();
};
