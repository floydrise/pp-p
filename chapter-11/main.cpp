#include "PPP/Graph.h"
#include "PPP/GUI.h"
#include "PPP/Window.h"

/*
[1] Make an 800-by-1000 Simple_window.
[2] Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that each square is 100 by 100).
[3] Make the eight squares on the diagonal starting from the top left corner red (use Rectangle).
[4] Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it on the grid (each image covering four squares).
If you can’t find an image that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of a larger image. Don’t obscure the red squares.
[5] Add a 100-by-100 image. Have it move around from square to square when you click the “Next” button. Just put wait_for_button() in a
loop with some code that picks a new square for your image.
 */

int main() {
    Graph_lib::Application app;
    Graph_lib::Window win{Graph_lib::Point{100, 100}, 800, 1000, "Rectangle"};
    Graph_lib::Vector_ref<Graph_lib::Rectangle> vr;
    Graph_lib::Vector_ref<Graph_lib::Image> img_vr;
    Graph_lib::Image cam{Graph_lib::Point{100, 0}, "camera.jpg"};

    // On click of the button move the camera image
    Graph_lib::Button btn{
        Graph_lib::Point{100, 100}, 60, 60, "Move",
        [&cam]() {
            cam.move(100, 0);
        }
    };


    // draw grid with red squares
    constexpr int max = 8;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            constexpr int size_rect = 100;
            const int x_coordinate = i * size_rect;
            const int y_coordinate = j * size_rect;

            vr.push_back(
                make_unique<Graph_lib::Rectangle>(Graph_lib::Point{x_coordinate, y_coordinate},
                                                  size_rect,
                                                  size_rect));
            win.attach(vr[vr.size() - 1]);
        }
        vr[i * 9].set_fill_color(Graph_lib::Color::red);
    }

    // display image
    constexpr int img_loop_max = 4;
    for (int i = 1; i < img_loop_max; ++i) {
        constexpr int size_rect = 200;
        constexpr int x_coordinate = 0;
        const int y_coordinate = i * size_rect;
        img_vr.push_back(make_unique<Graph_lib::Image>(Graph_lib::Point{x_coordinate, y_coordinate}, "MainBefore.jpg"));
        img_vr[img_vr.size() - 1].set_mask(Graph_lib::Point{0, 0}, 200, 200);
        img_vr[img_vr.size() - 1].set_color(Graph_lib::Color::cyan);
        win.attach(img_vr[img_vr.size() - 1]);
    }

    win.attach(cam);
    win.attach(btn);

    win.wait_for_button(&btn);
    app.gui_main();
}
