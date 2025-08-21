#include <fstream>
#include <ios>
#include <iostream>

#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

struct Distribution {
    int year;
    double young, middle, old;
};

class Scale {
    // data value to coordinate conversion
    int cbase; // coordinate base
    int vbase; // base of values
    double scale;

public:
    Scale(int b, int vb, double s) : cbase{b}, vbase{vb}, scale{s} {
    }

    int operator()(double v) const { return cbase + (v - vbase) * scale; }
};

std::istream &operator>>(std::istream &is, Distribution &d) {
    // assume format: {year : young middle old }
    char ch1 = 0, ch2 = 0, ch3 = 0;
    Distribution dd;
    if (is >> ch1 >> dd.year >> ch2 >> dd.young >> dd.middle >> dd.old >> ch3) {
        if (ch1 != '{' || ch2 != ':' || ch3 != '}') {
            is.clear(std::ios_base::failbit);
        } else {
            d = dd;
        }
    }
    return is;
};

int main() {
    Application app;
    const std::string file_name = "japanese-age-data.txt";

    constexpr int xmax = 600; // window size
    constexpr int ymax = 400;

    constexpr int xoffset = 100;
    constexpr int yoffset = 60;

    constexpr int xspace = 40;
    constexpr int yspace = 40;

    constexpr int xlength = xmax - xoffset - xspace;
    constexpr int ylength = ymax - yoffset - yspace;

    constexpr int base_year = 2010;
    constexpr int end_year = 2040;

    constexpr double xscale = static_cast<double>(xlength) / (end_year - base_year);
    constexpr double yscale = static_cast<double>(ylength) / 100;

    Scale xs{xoffset, base_year, xscale};
    Scale ys{ymax - yoffset, 0, -yscale};

    Open_polyline children;
    Open_polyline adults;
    Open_polyline aged;

    Simple_window win{Point{100, 100}, xmax, ymax, "Aging Japan"};


    Axis x{
        Axis::x, Point{xoffset, ymax - yoffset}, xlength, (end_year - base_year) / 5, // one notch per 5 years
        "year "
        "2010     2015     2020      2025      "
        "2030      2035    2040"
    };
    x.label.move(-100, 0);
    x.label.set_font_size(10);

    Axis y{Axis::y, Point{xoffset, ymax - yoffset}, ylength, 10, "% of population"};

    int now = 2023;
    Line current_year{Point{xs(now), ys(0)}, Point{xs(now), ys(100)}};
    current_year.set_style(Line_style::dash);

    std::ifstream ifs{file_name};

    if (!ifs) {
        Text err_label{Point{20, 20}, "Can't open file!"};
        win.attach(err_label);
        win.wait_for_button();
        throw runtime_error(format("Can't open file: {}", file_name));
    }

    for (Distribution d; ifs >> d;) {
        if (d.year < base_year || end_year < d.year) {
            throw runtime_error("Year out of range");
        }
        double all = d.young + d.middle + d.old;
        if (all - 100 > 1.5 || 100 - all > 1.5) {
            throw runtime_error("Percentages don't add up");
        }

        const int x = xs(d.year);
        children.add(Point{x, ys(d.young)});
        adults.add(Point{x, ys(d.middle)});
        aged.add(Point{x, ys(d.old)});

        Text children_label{Point{20, children.point(0).y}, "age 0−14"};
        children.set_color(Color::red);
        children_label.set_color(Color::red);
        children_label.set_font_size(10);
        children_label.set_style(Line_style::dash);

        Text adults_label{Point{20, adults.point(0).y}, "age 15−64"};
        adults.set_color(Color::blue);
        adults_label.set_color(Color::blue);
        adults_label.set_font_size(10);

        Text aged_label{Point{20, aged.point(0).y}, "age 65+"};
        aged.set_color(Color::dark_green);
        aged_label.set_color(Color::dark_green);
        aged_label.set_font_size(10);
        aged_label.set_style(Line_style::dashdotdot);

        win.attach(children);
        win.attach(adults);
        win.attach(aged);
        win.attach(children_label);
        win.attach(adults_label);
        win.attach(aged_label);
    }


    win.attach(x);
    win.attach(y);
    win.attach(current_year);

    win.wait_for_button();
}
