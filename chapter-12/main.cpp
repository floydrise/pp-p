#include "exercises/definitions/Striped_circle.h"
#include "exercises/definitions/Striped_rectangle.h"
#include "PPP/Point.h"
#include "PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Test"};
    Striped_circle circ{{100, 100}, 50};
    win.attach(circ);
    app.gui_main();
}
