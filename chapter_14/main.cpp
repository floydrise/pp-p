#include "classes/Lines_window.h"
#include "PPP/Window.h"


#include "PPP/GUI.h"

int main()
try {
    Application app; // create a GUI application
    Lines_window win{app, Point{100, 100}, 600, 400, "lines"}; // our window
    return app.gui_main();
} catch (exception &e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}
