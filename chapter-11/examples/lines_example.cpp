#include <QApplication>

#include "../PPP/Point.h"
#include "../PPP/Simple_window.h"

int main() try {
    Application app;
    Simple_window win{Point{100, 100}, 600, 400, "Lines"};

    Lines y;
    y.add(Point{100, 100}, Point{200, 100});
    y.add(Point{150, 50}, Point{150, 150});

    win.attach(y);

    app.gui_main();
} catch (...) {
    cerr << "Something went wrong! \n";
}
