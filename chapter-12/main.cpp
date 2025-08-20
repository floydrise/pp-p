#include "exercises/definitions/Striped_rectangle.h"
#include "PPP/Point.h"
#include "PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Test"};
    Striped_rectangle str_rec{Graph_lib::Point{100, 100}, 200, 50};
    win.attach(str_rec);
    app.gui_main();
}
