//
// Created by Stefan Petrov on 23.08.25.
//

#include "Fct.h"

Fct::Fct(std::function<double(double)> f, double r1, double r2, Graph_lib::Point orig,
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
