/*“Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw(). Each takes a Rectangle argument and returns a Point.
*These functions define “connection points” on and in the rectangle. For example, nw(r) is the northwest (top left) corner of a Rectangle called r.”
*/

#include "PPP/Graph.h"
#include "PPP/Point.h"

Graph_lib::Point nw(Graph_lib::Rectangle &r) {
    return r.point(0);
}

Graph_lib::Point ne(Graph_lib::Rectangle &r) {
    Graph_lib::Point main_pnt = nw(r);
    const int width = r.width();
    return {main_pnt.x + width, main_pnt.y};
}

Graph_lib::Point n(Graph_lib::Rectangle &r) {
    Graph_lib::Point main_pnt = nw(r);
    const int half = r.width() / 2;
    return {main_pnt.x + half, main_pnt.y};
}

Graph_lib::Point sw(Graph_lib::Rectangle &r) {
    Graph_lib::Point main_pnt = nw(r);
    const int height = r.height();
    return {main_pnt.x, main_pnt.y + height};
}

Graph_lib::Point se(Graph_lib::Rectangle &r) {
    Graph_lib::Point main_pnt = ne(r);
    const int height = r.height();
    return {main_pnt.x, main_pnt.y + height};
}

Graph_lib::Point s(Graph_lib::Rectangle &r) {
    Graph_lib::Point main_pnt = n(r);
    const int height = r.height();
    return {main_pnt.x, main_pnt.y + height};
}

Graph_lib::Point w(Graph_lib::Rectangle &r) {
    Graph_lib::Point main_pnt = nw(r);
    const int height = r.height();
    return {main_pnt.x, main_pnt.y + height / 2};
}

Graph_lib::Point e(Graph_lib::Rectangle &r) {
    Graph_lib::Point main_pnt = ne(r);
    const int height = r.height();
    return {main_pnt.x, main_pnt.y + height / 2};
}


Graph_lib::Point center(Graph_lib::Rectangle &r) {
    Graph_lib::Point nw_point = nw(r);
    Graph_lib::Point se_point = se(r);
    return {(nw_point.x + se_point.x) / 2, (nw_point.y + se_point.y) / 2};
}
