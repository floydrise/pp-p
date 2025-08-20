#include "exercises/definitions/Octagon.h"
#include "exercises/definitions/Rounded.h"
#include "PPP/Point.h"
#include "PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Test"};
    Rounded round{{200, 100}, 100, 300};
    win.attach(round);
    app.gui_main();
}
