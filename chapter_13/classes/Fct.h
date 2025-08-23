//
// Created by Stefan Petrov on 23.08.25.
//

#ifndef FCT_H
#define FCT_H
#include "PPP/Graph.h"

struct Range {
    double min_range;
    double max_range;
};

struct Scale {
    double xscale;
    double yscale;
};

class Fct : Graph_lib::Open_polyline {
public:
    Fct(std::function<double(double)> f, double r1, double r2, Graph_lib::Point orig, int count = 100,
        double xscale = 25,
        double yscale = 25);

    void reset_fn(const function<double(double)> &new_fn) {
        fn = new_fn;
    };

    void reset_ranges(double min_range, double max_range) {
        range.min_range = min_range;
        range.max_range = max_range;
    };

    void reset_point(const Graph_lib::Point &new_pt) { origin_p = new_pt; };

    void reset_count(const int new_ct) { iterate = new_ct; };

    void reset_scale(const double xscale, double yscale) {
        scale.xscale = xscale;
        scale.yscale = yscale;
    };

private:
    function<double(double)> fn;
    Range range;
    Graph_lib::Point origin_p;
    int iterate;
    Scale scale;
};


#endif //FCT_H
