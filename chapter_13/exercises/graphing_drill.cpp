#include "PPP/Simple_window.h"
#include "PPP/Window.h"

double one(double) { return 1; }
double slope(const double x) { return 0.5 * x; }
double square(const double x) { return x * x; }
double sloping_cos(const double x) { return cos(x) + slope(x); };

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

    // App and Window
    Application app;
    Simple_window window{{400, 200}, win_w, win_h, "Function graphs"};

    Function f1{one, range_min, range_max, orig, count, x_scale, y_scale};
    Function f2{slope, range_min, range_max, orig, count, x_scale, y_scale};
    Function f3{square, range_min, range_max, orig, count, x_scale, y_scale};
    Function f4{[](const double x) -> double { return cos(x); }, range_min, range_max, orig, count, x_scale, y_scale};
    Function f5{sloping_cos, range_min, range_max, orig, count, x_scale, y_scale};

    // Axis
    Axis xa{Axis::x, {padding, y_mid}, axis_len, axis_len / x_scale, "1 == 20 pixels"};
    Axis ya{Axis::y, {x_mid, win_h - padding}, axis_len, axis_len / y_scale, "1 == 20 pixels"};

    // Labels
    Text f2_label{{100, 400}, "0.5x"};

    // Color
    xa.set_color(Color::red);
    ya.set_color(Color::red);
    f1.set_color(Color::green);
    f2.set_color(Color::yellow);
    f3.set_color(Color::cyan);
    f4.set_color(Color::blue);
    f5.set_color(Color::magenta);


    // Attach
    window.attach(xa);
    window.attach(ya);
    window.attach(f1);
    window.attach(f2);
    window.attach(f2_label);
    window.attach(f3);
    window.attach(f4);
    window.attach(f5);

    app.gui_main();
};
