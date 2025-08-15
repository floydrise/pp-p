#include "PPP/Graph.h"
#include "PPP/GUI.h"
#include "PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 800, 1000, "Rectangle"};

    Graph_lib::Rectangle rect{{100, 100}, 80, 50};

    app.gui_main();
}
