#include "PPP/Graph.h"
#include "PPP/GUI.h"
#include "PPP/Window.h"

#include "PPP/Arrow.h"
#include "PPP/Box.h"

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 800, 1000, "Rectangle"};

    Box win_class{Graph_lib::Point{160, 20}, 120, 40, "Window"};
    win_class.set_fill_color(Graph_lib::Color::cyan);
    Box simple_win_class{Graph_lib::Point{160, 100}, 120, 40, "Simple_Window"};
    simple_win_class.set_fill_color(Graph_lib::Color::cyan);
    Arrow win_simple_win_arrow{simple_win_class.rect.north(), win_class.rect.south()};

    Box line_style_class{Graph_lib::Point{300, 20}, 120, 40, "Line_style"};
    line_style_class.set_fill_color(Graph_lib::Color::cyan);
    Box shape_class{Graph_lib::Point{300, 100}, 120, 40, "Shape"};
    shape_class.set_fill_color(Graph_lib::Color::cyan);

    Box color_class{Graph_lib::Point{440, 20}, 120, 40, "Color"};
    color_class.set_fill_color(Graph_lib::Color::cyan);
    Box point_class{Graph_lib::Point{440, 100}, 120, 40, "Point"};
    point_class.set_fill_color(Graph_lib::Color::cyan);

    // Line
    Box line_class{Graph_lib::Point{20 + 60, 200}, 60, 40, "Line"};
    line_class.set_fill_color(Graph_lib::Color::cyan);
    Arrow line_shape_arrow{line_class.rect.north(), shape_class.rect.south()};

    // Lines
    Box lines_class{Graph_lib::Point{100 + 60, 200}, 60, 40, "Lines"};
    lines_class.set_fill_color(Graph_lib::Color::cyan);
    Arrow lines_shape_arrow{lines_class.rect.north(), shape_class.rect.south()};

    // Polygon
    Box poly_class{Graph_lib::Point{180 + 60, 200}, 60, 40, "Polygon"};
    poly_class.set_fill_color(Graph_lib::Color::cyan);
    poly_class.label.set_font_size(10);
    Arrow poly_shape_arrow{poly_class.rect.north(), shape_class.rect.south()};

    // Axis
    Box axis_class{Graph_lib::Point{260 + 60, 200}, 60, 40, "Axis"};
    axis_class.set_fill_color(Graph_lib::Color::cyan);
    Arrow axis_shape_arrow{axis_class.rect.north(), shape_class.rect.south()};

    Box rect_class{Graph_lib::Point{340 + 60, 200}, 60, 40, "Rectangle"};
    rect_class.set_fill_color(Graph_lib::Color::cyan);
    rect_class.label.set_font_size(10);
    Arrow rect_shape_arrow{rect_class.rect.north(), shape_class.rect.south()};

    Box text_class{Graph_lib::Point{420 + 60, 200}, 60, 40, "Text"};
    text_class.set_fill_color(Graph_lib::Color::cyan);
    Arrow text_shape_arrow{text_class.rect.north(), shape_class.rect.south()};

    Box image_class{Graph_lib::Point{500 + 60, 200}, 60, 40, "Image"};
    image_class.set_fill_color(Graph_lib::Color::cyan);
    Arrow image_shape_arrow{image_class.rect.north(), shape_class.rect.south()};

    win.attach(win_class);
    win.attach(simple_win_class);
    win.attach(win_simple_win_arrow);
    win.attach(line_style_class);
    win.attach(shape_class);
    win.attach(color_class);
    win.attach(point_class);
    win.attach(line_class);
    win.attach(line_shape_arrow);
    win.attach(lines_class);
    win.attach(lines_shape_arrow);
    win.attach(poly_class);
    win.attach(poly_shape_arrow);
    win.attach(axis_class);
    win.attach(axis_shape_arrow);
    win.attach(rect_class);
    win.attach(rect_shape_arrow);
    win.attach(text_class);
    win.attach(text_shape_arrow);
    win.attach(image_class);
    win.attach(image_shape_arrow);

    app.gui_main();
}
