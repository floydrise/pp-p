#include "PPP/Graph.h"
#include "PPP/GUI.h"
#include "PPP/Window.h"

#include "PPP/Arrow.h"
#include "PPP/Box.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 800, 1000, "Rectangle"};

    Box box{Graph_lib::Point{100, 100}, 200, 60, "Line_style"};
    win.attach(box);

    app.gui_main();
}
