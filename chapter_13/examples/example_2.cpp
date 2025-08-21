#include <complex>

#include "PPP/Simple_window.h"
#include "PPP/Window.h"

// initially returning an int, values overflow and result
// in incorrect answers
double fac(int n) {
    double r = 1;
    while (n > 1) {
        r *= n;
        --n;
    }
    return r;
}

double term(const double x, const int n) { return std::pow(x, n) / fac(n); };

double exp_n(const double x, const int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += term(x, i);
    }
    return sum;
}

int main() {
    Graph_lib::Application app;

    constexpr int xmax = 600; // window size
    constexpr int ymax = 400;

    constexpr int x_orig = xmax / 2; // center of win
    constexpr int y_orig = ymax / 2;

    constexpr Graph_lib::Point orig{x_orig, y_orig};

    constexpr int r_min = -10; // range [-10, 11]
    constexpr int r_max = 11;

    constexpr int n_points = 200;

    constexpr int x_scale = 30; // scaling factors
    constexpr int y_scale = 30;

    constexpr int xlen = xmax - 40; // make axis smaller than win
    constexpr int ylen = ymax - 40;

    Simple_window win{Graph_lib::Point{100, 100}, xmax, ymax, "Three fns"};

    Graph_lib::Function real_exp{[](const double x) { return exp(x); }, r_min, r_max, orig, n_points, x_scale, y_scale};
    real_exp.set_color(Graph_lib::Color::blue);

    Graph_lib::Axis x_axis{Graph_lib::Axis::x, {20, y_orig}, xlen, xlen / x_scale, "one notch == 1"};
    Graph_lib::Axis y_axis{Graph_lib::Axis::y, {x_orig, ylen + 20}, ylen, ylen / y_scale, "one notch == 1"};
    x_axis.set_color(Graph_lib::Color::red);
    y_axis.set_color(Graph_lib::Color::red);
    x_axis.label.move(130, 0);
    y_axis.label.move(-40, -10);

    win.attach(x_axis);
    win.attach(y_axis);
    win.attach(real_exp);

    for (int n = 0; n < 50; ++n) {
        ostringstream ss;
        ss << "exp approximation; n==" << n;
        win.set_label(ss.str());

        Graph_lib::Function e{
            [n](const double x) { return exp_n(x, n); }, r_min, r_max, orig, n_points, x_scale, y_scale
        };

        win.attach(e);
        win.wait_for_button();
        win.detach(e);
    }

    app.gui_main();
}
