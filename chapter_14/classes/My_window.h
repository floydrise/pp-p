//
// Created by Stefan Petrov on 27.08.25.
//

#ifndef MY_WINDOW_H
#define MY_WINDOW_H
#include "PPP/GUI.h"
#include "PPP/Window.h"


struct My_window : Graph_lib::Window {
    My_window(Graph_lib::Point xy, int w, int h, const string &title);

    ~My_window();

    void wait_for_button();

private:
    Graph_lib::Button next_button;
    Graph_lib::Button quit_button;
};


#endif //MY_WINDOW_H
