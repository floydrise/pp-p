#include "exercises/Frowny.h"
#include "exercises/Immobile_circle.h"
#include "exercises/Smiley.h"
#include "PPP/Point.h"
#include "PPP/Window.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 600, 400, "Test"};
    Immobile_circle imb_cl{Graph_lib::Point{100, 100}, 50};
    // imb_cl.move(); -> this won't work, move() is private and overridden to do nothing
    // check classes
    win.attach(imb_cl);
    app.gui_main();
}
