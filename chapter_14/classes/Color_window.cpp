//
// Created by Stefan Petrov on 27.08.25.
//

#include "Color_window.h"

Color_window::Color_window(Application &app, Point xy, int w, int h, const string &title)
    : Lines_window{app, xy, w, h, title},
      menu_button{
          Point{x_max() - 80, 30}, 80, 20, "color menu",
          [&] {
              menu_button.hide();
              color_menu.show();
          }
      },
      color_menu{Point{x_max() - 70, 40}, 70, 20, Menu::vertical, "color"} {
    attach(color_menu);
    color_menu.attach(make_unique<Button>(Point{0, 0}, 0, 0, "red",
                                          [&] {
                                              change(Color::red);
                                              hide_menu();
                                          }));
    color_menu.attach(make_unique<Button>(Point{0, 0}, 0, 0, "blue",
                                          [&] {
                                              change(Color::blue);
                                              hide_menu();
                                          }));
    color_menu.attach(make_unique<Button>(Point{0, 0}, 0, 0, "black",
                                          [&] {
                                              change(Color::black);
                                              hide_menu();
                                          }));
    attach(menu_button);
    hide_menu();
}
