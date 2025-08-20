#include "exercises/definitions/Octagon.h"
#include "PPP/Point.h"
#include "PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Test"};
    Octagon oct{{200, 200}, 20};
    win.attach(oct);
    app.gui_main();
}
