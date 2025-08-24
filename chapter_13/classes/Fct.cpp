//
// Created by Stefan Petrov on 23.08.25.
//

#include "Fct.h"

My_Fct::My_Fct(std::function<double(double)> f, double r1, double r2, Graph_lib::Point orig,
               int count, double xscale,
               double yscale): fn(f), range{r1, r2}, origin_p(orig), iterate(count), scale{xscale, yscale} {
    if (r2 - r1 <= 0) error("bad graphing range");
    if (count <= 0) error("non-positive graphing count");
    const double dist = (r2 - r1) / count;
    double r = r1;
    for (int i = 0; i < count; ++i) {
        add(Graph_lib::Point{orig.x + static_cast<int>(r * xscale), orig.y - static_cast<int>(f(r) * yscale)});
        r += dist;
    }
}

void My_Fct::rebuild() {
    if (range.max_range - range.min_range <= 0) error("bad graphing range");
    if (iterate <= 0) error("non-positive graphing count");
    const double dist = (range.max_range - range.min_range) / iterate;
    double r = range.min_range;
    for (int i = 0; i < iterate; ++i) {
        add(Graph_lib::Point{
            origin_p.x + static_cast<int>(r * scale.xscale), origin_p.y - static_cast<int>(fn(r) * scale.yscale)
        });
        r += dist;
    }
}

void My_Fct::refresh() {
    clear();
    rebuild();
    redraw();
}


void My_Fct::reset_fn(const function<double(double)> &new_fn) {
    fn = new_fn;
    refresh();
};

void My_Fct::reset_ranges(double min_range, double max_range) {
    range.min_range = min_range;
    range.max_range = max_range;
    refresh();
}

void My_Fct::reset_point(const Graph_lib::Point &new_pt) {
    origin_p = new_pt;
    refresh();
}

void My_Fct::reset_count(const int new_ct) {
    iterate = new_ct;
    refresh();
}

void My_Fct::reset_scale(double xscale, double yscale) {
    scale.xscale = xscale;
    scale.yscale = yscale;
    refresh();
}
