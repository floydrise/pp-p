//
// Created by Stefan Petrov on 26.08.25.
//

#ifndef LINES_WINDOW_H
#define LINES_WINDOW_H
#include "PPP/GUI.h"
#include "PPP/Window.h"

using namespace Graph_lib;

struct Lines_window : Window {
    Lines_window(Application &application, Point xy, int w, int h, const string &title);

    Open_polyline lines;

    void wait_for_button();

private:
    Application *app = nullptr;
    Button quit_button; // a Widget
    In_box next_xy; // a Widget
    Out_box xy_out; // a Shape
    void next();

    void quit();
};


#endif //LINES_WINDOW_H
