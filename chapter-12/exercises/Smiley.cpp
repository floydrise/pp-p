#include "Smiley.h"

#include "PPP/Window.h"

void Smiley::draw_specifics(Graph_lib::Painter &painter) const {
    Circle::draw_specifics(painter);
    painter.draw_centered_text({center().x - 20, center().y - 20}, "X");
    painter.draw_centered_text({center().x + 20, center().y - 20}, "X");
    Graph_lib::Arc smile({center().x, center().y + 10}, radius() / 2, radius() / 3, 180, 180);
    smile.draw_specifics(painter);
}
