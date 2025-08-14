#include "../PPP/Graph.h"
#include "../PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Rectangle"};

    Graph_lib::Ellipse e1{Graph_lib::Point{200, 200}, 50, 50};
    Graph_lib::Ellipse e2{Graph_lib::Point{200, 200}, 100, 50};
    Graph_lib::Ellipse e3{Graph_lib::Point{200, 200}, 100, 150};

    win.attach(e1);
    win.attach(e2);
    win.attach(e3);
    app.gui_main();
}
