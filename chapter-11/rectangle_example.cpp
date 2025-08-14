#include "PPP/Graph.h"
#include "PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Rectangle"};

    Graph_lib::Rectangle rect00{Graph_lib::Point{150, 100}, 200, 100};
    Graph_lib::Rectangle rect11{Graph_lib::Point{50, 50}, Graph_lib::Point{250, 150}};
    Graph_lib::Rectangle rect12{Graph_lib::Point{50, 150}, Graph_lib::Point{250, 250}}; // just below rect11
    Graph_lib::Rectangle rect21{Graph_lib::Point{250, 50}, 200, 100}; // just to the right of rect11
    Graph_lib::Rectangle rect22{Graph_lib::Point{250, 150}, 200, 100}; // just below rect21

    rect00.set_fill_color(Graph_lib::Color::yellow);
    rect11.set_fill_color(Graph_lib::Color::blue);
    rect12.set_fill_color(Graph_lib::Color::red);
    rect21.set_fill_color(Graph_lib::Color::green);

    win.attach(rect00);
    win.attach(rect11);
    win.attach(rect12);
    win.attach(rect21);
    win.attach(rect22);

    app.gui_main();
}
