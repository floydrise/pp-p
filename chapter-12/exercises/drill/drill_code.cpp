#include "B1.h"

int main() {
    /*Drill::B1 b1_obj;
    b1_obj.vf();
    b1_obj.f();
    Drill::D1 d1;
    Drill::B1 &ref = d1;
    ref.vf();
    ref.f();
    */

    Drill::D2 d2;
    d2.pvf();
    d2.vf();
    d2.f();

    Drill::D21 d21("Test");
    Drill::D22 d22(23);

    Drill::f(d21);
    Drill::f(d22);
    return 0;
}
