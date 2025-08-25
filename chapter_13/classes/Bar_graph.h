//
// Created by Stefan Petrov on 25.08.25.
//

#ifndef BAR_GRAPH_H
#define BAR_GRAPH_H
#include "PPP/Graph.h"


class Bar_graph : public Graph_lib::Shape {
public:
    Bar_graph() {
    };
    void push_back(double val) { values.push_back(val); };

    void pop_back() {
        if (values.empty()) {
            throw runtime_error("Values vector empty");
        }
        values.pop_back();
    }

    void draw_specifics(Graph_lib::Painter &painter) const override;

private:
    vector<double> values;
};


#endif //BAR_GRAPH_H
