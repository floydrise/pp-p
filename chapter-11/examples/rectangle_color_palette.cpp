#include "../PPP/Graph.h"
#include "../PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Rectangle"};

    Graph_lib::Vector_ref<Graph_lib::Rectangle> vr;

    constexpr int max = 32;
    int color_index = 0;

    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < 8; ++j) {
            constexpr int y_offset = 100;
            constexpr int x_offset = 10;
            constexpr int size_rect = 18;
            const int x_coordinate = i * size_rect + x_offset;
            const int y_coordinate = j * size_rect + y_offset;
            vr.push_back(
                make_unique<Graph_lib::Rectangle>(Graph_lib::Point{x_coordinate, y_coordinate},
                                                  size_rect,
                                                  size_rect));
            vr[vr.size() - 1].set_fill_color(color_index);
            ++color_index;
            win.attach(vr[vr.size() - 1]);
        }
    }

    app.gui_main();
}
