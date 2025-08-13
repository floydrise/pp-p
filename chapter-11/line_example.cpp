#include <QApplication>

#include "PPP/Point.h"
#include "PPP/Simple_window.h"

int main() try {
    Application app;
    constexpr Point x{100, 100};

    Simple_window win{x, 600, 400, "two lines"};

    Line horizontal{x, Point{200, 100}};
    Line vertical{Point{150, 50}, Point{150, 150}};

    win.attach(horizontal);
    win.attach(vertical);

    app.gui_main();
} catch (...) {
    cerr << "Something went wrong! \n";
}
