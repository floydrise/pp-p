#include "PPP/Graph.h"
#include "PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 800, 1000, "Rectangle"};

    Graph_lib::Vector_ref<Graph_lib::Rectangle> vr;

    constexpr int max = 8;

    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            constexpr int size_rect = 100;
            const int x_coordinate = i * size_rect;
            const int y_coordinate = j * size_rect;

            vr.push_back(
                make_unique<Graph_lib::Rectangle>(Graph_lib::Point{x_coordinate, y_coordinate},
                                                  size_rect,
                                                  size_rect));
            win.attach(vr[vr.size() - 1]);
        }
        vr[i * 9].set_fill_color(Graph_lib::Color::red);
    }

    app.gui_main();
}
