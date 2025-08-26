//
// Created by Stefan Petrov on 26.08.25.
//

#include "Lines_window.h"

Lines_window::Lines_window(Application &application, Point xy, int w, int h, const string &title)
    : Window{xy, w, h, title},
      app(&application),
      quit_button{Point{x_max() - 70, 0}, 70, 20, "Quit", [this]() { quit(); }},
      next_xy{Point{250, 0}, 50, 20, "next xy:", [this]() { next(); }},
      xy_out{Point{10, 10}, "current (x,y): "} {
    attach(lines);
    attach(quit_button);

    next_xy.hide_buttons(); // a Qt input box comes with buttons; we decided to hide them
    attach(next_xy);
    next_xy.show(); // but we do want the box itself to show

    xy_out.label.set_font_size(8); // use a smaller than default font
    xy_out.data.set_font_size(8);
    attach(xy_out);
}

void Lines_window::quit() {
    end_button_wait(); // don't wait anymore
    next_xy.dismiss(); // clean up
    app->quit();
}


void Lines_window::next() // the action performed by next_xy when woken up
{
    if (next_xy.last_result() == In_box::accepted) {
        // check if the value has changed
        string s = next_xy.last_string_value(); // read coordinate pair
        istringstream iss{s};
        int x = 0;
        char ch = 0;
        int y = 0;
        iss >> x >> ch >> y;
        lines.add(Point{x, y});

        ostringstream oss; // update current position readout
        oss << '(' << x << ',' << y << ')';
        xy_out.put(oss.str());
    }
    next_xy.clear_last_result();
}
