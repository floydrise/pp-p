//
// Created by Stefan Petrov on 23.08.25.
//

#ifndef FCT_H
#define FCT_H
#include "PPP/Graph.h"

// In order for this to work and simplify things,
// I've added a void clear() fn to Shape class so
// points stored inside vector<Points> can be cleared easily

struct Range {
    double min_range;
    double max_range;
};

struct Scale {
    double xscale;
    double yscale;
};

class My_Fct : public Graph_lib::Open_polyline {
public:
    My_Fct(std::function<double(double)> f, double r1, double r2, Graph_lib::Point orig, int count = 100,
           double xscale = 25,
           double yscale = 25);

    void reset_fn(const function<double(double)> &new_fn);

    void reset_ranges(double min_range, double max_range);

    void reset_point(const Graph_lib::Point &new_pt);

    void reset_count(int new_ct);

    void reset_scale(double xscale, double yscale);

private:
    function<double(double)> fn; // f
    Range range; // r1, r2
    Graph_lib::Point origin_p; // orig
    int iterate; // count
    Scale scale; // xscale, yscale

    void rebuild();
    void refresh();
};


#endif //FCT_H
