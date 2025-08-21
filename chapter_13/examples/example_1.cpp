#include <valarray>

#include "PPP/Point.h"
#include "PPP/Window.h"

double one(double) { return 1; }
double slope(const double x) { return 0.5 * x; }
double square(const double x) { return x * x; }
double dcos(const double x) { return cos(x); };
double sloping_cos(const double x) { return cos(x) + slope(x); }

int main() {
    Graph_lib::Application app;

    constexpr int xmax = 600; // window size
    constexpr int ymax = 400;

    constexpr int x_orig = xmax / 2; // center of win
    constexpr int y_orig = ymax / 2;

    constexpr Graph_lib::Point orig{x_orig, y_orig};

    constexpr int r_min = -10; // range [-10, 11]
    constexpr int r_max = 11;

    constexpr int n_points = 400;

    constexpr int x_scale = 30; // scaling factors
    constexpr int y_scale = 30;

    constexpr int xlen = xmax - 40; // make axis smaller than win
    constexpr int ylen = ymax - 40;

    Graph_lib::Window win{Graph_lib::Point{100, 100}, xmax, ymax, "Three fns"};

    // Functions
    Graph_lib::Function s{one, r_min, r_max, orig, n_points, x_scale, y_scale};
    Graph_lib::Function s2{slope, r_min, r_max, orig, n_points, x_scale, y_scale};
    Graph_lib::Function s3{square, r_min, r_max, orig, n_points, x_scale, y_scale};
    Graph_lib::Function s4{dcos, r_min, r_max, orig, n_points, x_scale, y_scale};
    Graph_lib::Function s5{sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale};

    // Labels
    Graph_lib::Text ts{{100, y_orig - 40}, "one"};
    Graph_lib::Text ts2{{100, y_orig + y_orig / 2 - 20}, "0.5*x"};
    Graph_lib::Text ts3{{x_orig - 100, 20}, "x*x"};

    // Colors
    s4.set_color(Graph_lib::Color::blue);
    s5.set_color(Graph_lib::Color::green);

    // Axis
    Graph_lib::Axis x_axis{Graph_lib::Axis::x, {20, y_orig}, xlen, xlen / x_scale, "one notch == 1"};
    Graph_lib::Axis y_axis{Graph_lib::Axis::y, {x_orig, ylen + 20}, ylen, ylen / y_scale, "one notch == 1"};
    x_axis.set_color(Graph_lib::Color::red);
    y_axis.set_color(Graph_lib::Color::red);
    x_axis.label.move(130, 0);
    y_axis.label.move(-40, -10);

    win.attach(s);
    win.attach(s2);
    win.attach(s3);
    win.attach(s4);
    win.attach(s5);
    win.attach(ts);
    win.attach(ts2);
    win.attach(ts3);
    win.attach(x_axis);
    win.attach(y_axis);

    app.gui_main();
}
