#include "classes/Color_window.h"
#include "classes/Lines_window.h"
#include "PPP/Window.h"


#include "PPP/GUI.h"

// This does NOT run - app.gui_main() is a void function which does not return a number

int main()
try {
    Application app; // create a GUI application
    Lines_window win{app, Point{100, 100}, 600, 400, "lines"}; // our window
    Color_window color_win{app, Point{100, 100}, 600, 400, "Color menu"};
    win.wait_for_button();
    return app.gui_main();
} catch (exception &e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}
