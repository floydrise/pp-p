//
// Created by Stefan Petrov on 27.08.25.
//

#ifndef COLOR_WINDOW_H
#define COLOR_WINDOW_H
#include "Lines_window.h"


struct Color_window : Lines_window {
    Color_window(Application &app, Point xy, int w, int h, const string &title);

private:
    void change(Color c) { lines.set_color(c); }

    void hide_menu() {
        color_menu.hide();
        menu_button.show();
    }

    Button menu_button;
    Menu color_menu;
};


#endif //COLOR_WINDOW_H
