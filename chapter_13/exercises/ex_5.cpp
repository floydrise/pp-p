#include <complex>
#include <iostream>

#include "classes/Fct.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

//“Animate” (as in §13.5) the series 1−1/3+1/5−1/7+1/9−1/11+ .... It is known as Leibniz’s series and converges to pi/4.
double leibniz_series(const double n) {
    double sum = 0;
    for (int i = 0; i < static_cast<int>(n); ++i) {
        sum += ((i % 2 == 0) ? 1.0 : -1.0) / (2 * i + 1);
    }
    return sum;
};

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

    window.attach(xa);
    window.attach(ya);

    Function pi_line{
        [](double) { return M_PI / 4; },
        range_min, range_max, orig, count, x_scale, y_scale
    };
    pi_line.set_color(Color::red);
    window.attach(pi_line);

    for (int n = 0; n < 50; ++n) {
        // get next approximation:
        Function leb{[n](double) { return leibniz_series(n); }, range_min, range_max, orig, count, x_scale, y_scale};

        window.attach(leb);
        window.wait_for_button();
        window.detach(leb);
    }


    app.gui_main();
};
