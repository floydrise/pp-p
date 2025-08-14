#include "PPP/Graph.h"
#include "PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Rectangle"};

    Graph_lib::Circle c1{Graph_lib::Point{100, 200}, 50};
    Graph_lib::Circle c2{Graph_lib::Point{150, 200}, 100};
    Graph_lib::Circle c3{Graph_lib::Point{200, 200}, 150};

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);

    app.gui_main();
}
