//
// Created by Stefan Petrov on 27.08.25.
//

#include "My_window.h"

#include "PPP/GUI_private.h"

My_window::My_window(Graph_lib::Point xy, int w, int h, const string &title) : Window(xy, w, h, title),
                                                                               next_button(
                                                                                   Graph_lib::Point{w - 70, 0}, 70, 20,
                                                                                   "Next", [] {
                                                                                   }), quit_button(
                                                                                   Graph_lib::Point{w - 140, 0}, 70, 20,
                                                                                   "Quit", [] {
                                                                                   }) {
    attach(next_button);
    attach(quit_button);
}

My_window::~My_window() {
}

void My_window::wait_for_button() {
    get_impl().wait_for_button(&next_button);
    get_impl().wait_for_button(&quit_button);
}
