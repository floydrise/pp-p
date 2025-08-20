#include "exercises/Frowny.h"
#include "exercises/Smiley.h"
#include "PPP/Point.h"
#include "PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Test"};
    Smiley smile{Graph_lib::Point{100, 100}, 50};
    Frowny frowny{Graph_lib::Point{200, 200}, 50};
    win.attach(frowny);
    win.attach(smile);
    app.gui_main();
}
