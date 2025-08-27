#include "PPP/Window.h"

// This is also not working as supposed

int main() {
    constexpr int seconds = 1000;
    constexpr int yellow_delay = 10 * seconds;
    constexpr int red_green_delay = 120 * seconds;

    Graph_lib::Application app;
    Graph_lib::Window w{140, 240, "Traffic light"};

    Graph_lib::Rectangle r{{10, 10}, 120, 220};
    r.set_fill_color(Graph_lib::Color::black);

    Graph_lib::Circle red{{70, 50}, 30};
    Graph_lib::Circle amber{{70, 120}, 30};
    Graph_lib::Circle green{{70, 190}, 30};

    w.attach(r);
    w.attach(red);
    w.attach(amber);
    w.attach(green);
    while (true)
        for (int i = 0; i < 3; ++i) {
            red.set_fill_color(Graph_lib::Color::red);
            w.timer_wait(red_green_delay);

            amber.set_fill_color(Graph_lib::Color::yellow);
            w.timer_wait(yellow_delay);

            red.set_fill_color(Graph_lib::Color::black);
            amber.set_fill_color(Graph_lib::Color::black);
            green.set_fill_color(Graph_lib::Color::green);

            w.timer_wait(red_green_delay);
            amber.set_fill_color(Graph_lib::Color::yellow);
            green.set_fill_color(Graph_lib::Color::black);
            w.timer_wait(yellow_delay);

            amber.set_fill_color(Graph_lib::Color::black);
        }


    app.gui_main();
}
