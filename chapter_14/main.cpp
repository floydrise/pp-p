#include "classes/My_window.h"
#include "PPP/Simple_window.h"
#include "PPP/Window.h"

int main() {
    Application app;
    My_window win{{100, 100}, 600, 400, "My window"};
    win.wait_for_button();
}
