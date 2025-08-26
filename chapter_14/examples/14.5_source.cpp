#include "classes/Lines_window.h"
#include "PPP/Window.h"

int main()
try {
    Graph_lib::Application app; // create a GUI application
    Lines_window win{app, Graph_lib::Point{100, 100}, 600, 400, "lines"}; // our window
    app.gui_main(); // start the GUI application
} catch (exception &e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}
