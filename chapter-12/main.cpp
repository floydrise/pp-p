#include <QApplication>
#include <QPushButton>

#include "exercises/drill/B1.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    Drill::D21 d21("Test");
    Drill::D22 d22(23);
    Drill::f(d21);
    Drill::f(d22);

    return QApplication::exec();
}
