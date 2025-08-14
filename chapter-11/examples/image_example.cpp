#include "../PPP/Graph.h"
#include "../PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 600, "Rectangle"};

    Graph_lib::Image img{Graph_lib::Point{0, 0}, "mirror.png"};

    win.attach(img);

    app.gui_main();
}
