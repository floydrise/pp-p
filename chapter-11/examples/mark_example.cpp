#include "../PPP/Graph.h"
#include "../PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Rectangle"};

    Graph_lib::Mark m1{Graph_lib::Point{100, 200}, 'x'};
    Graph_lib::Mark m2{Graph_lib::Point{150, 200}, 'y'};
    Graph_lib::Mark m3{Graph_lib::Point{200, 200}, 'z'};

    Graph_lib::Circle c1{Graph_lib::Point{100, 200}, 50};
    Graph_lib::Circle c2{Graph_lib::Point{150, 200}, 100};
    Graph_lib::Circle c3{Graph_lib::Point{200, 200}, 150};

    m1.set_color(Graph_lib::Color::red);
    c1.set_color(Graph_lib::Color::red);

    m2.set_color(Graph_lib::Color::blue);
    c2.set_color(Graph_lib::Color::blue);

    m3.set_color(Graph_lib::Color::green);
    c3.set_color(Graph_lib::Color::green);

    win.attach(m1);
    win.attach(m2);
    win.attach(m3);
    win.attach(c1);
    win.attach(c2);
    win.attach(c3);

    app.gui_main();
}
