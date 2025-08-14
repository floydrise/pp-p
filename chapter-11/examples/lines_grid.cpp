#include "../PPP/Point.h"
#include "../PPP/Simple_window.h"

int main() try {
    Application app;
    Simple_window win{Point{100, 100}, 600, 400, "Lines"};

    const int x_size = win.x_max();
    const int y_size = win.y_max();
    constexpr int x_grid = 80;
    constexpr int y_grid = 40;

    Lines grid;

    for (int x = x_grid; x < x_size; x += x_grid) {
        grid.add(Point{x, 0}, Point{x, y_size}); // vertical
    }
    for (int y = y_grid; y < y_size; y += y_grid) {
        grid.add(Point{0, y}, Point{x_size, y}); // horizontal
    }

    // set color and style
    grid.set_color(Color::blue);
    grid.set_style(Line_style{Line_style::dash, 2});

    win.attach(grid);

    app.gui_main();
} catch (...) {
    cerr << "Something went wrong! \n";
}
