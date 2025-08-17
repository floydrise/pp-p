#include "PPP/Graph.h"
#include "PPP/GUI.h"
#include "PPP/Window.h"

#include "PPP/Arrow.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 800, 1000, "Rectangle"};

    Arrow arrow{Graph_lib::Point{100, 100}, Graph_lib::Point{100, 100}};
    win.attach(arrow);

    app.gui_main();
}
