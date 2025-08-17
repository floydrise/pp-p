#include "PPP/Graph.h"
#include "PPP/GUI.h"
#include "PPP/Window.h"

#include "PPP/Arrow.h"
#include "PPP/Box.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 800, 1000, "Rectangle"};

    Box win_class{Graph_lib::Point{20, 20}, 120, 40, "Window"};
    win_class.set_fill_color(Graph_lib::Color::cyan);
    Box simple_win_class{Graph_lib::Point{20, 100}, 120, 40, "Simple_Window"};
    simple_win_class.set_fill_color(Graph_lib::Color::cyan);
    Arrow win_simple_win_arrow{simple_win_class.rect.north(), win_class.rect.south()};

    win.attach(win_class);
    win.attach(simple_win_class);
    win.attach(win_simple_win_arrow);

    app.gui_main();
}
