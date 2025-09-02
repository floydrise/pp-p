#include <iostream>

#include "Linked_list.h"

void print_all(Linked_list *p) {
    std::cout << "{ ";
    while (p) {
        std::cout << p->value;
        if ((p = p->next()))
            std::cout << ", ";
    }
    std::cout << " }";
}

int main() {
    auto *norse_gods = new Linked_list{"Thor"};
    norse_gods = norse_gods->insert(new Linked_list{"Odin"});
    norse_gods = norse_gods->insert(new Linked_list{"Zeus"});
    norse_gods = norse_gods->insert(new Linked_list{"Freja"});

    auto *greek_gods = new Linked_list{"Hera"};
    greek_gods = greek_gods->insert(new Linked_list{"Athena"});
    greek_gods = greek_gods->insert(new Linked_list{"Mars"});
    greek_gods = greek_gods->insert(new Linked_list{"Poseidon"});


    Linked_list *p = greek_gods->find("Mars");
    if (p) {
        p->value = "Ares";
    }

    Linked_list *p2 = norse_gods->find("Zeus");
    if (p2) {
        if (p2 == norse_gods) {
            norse_gods = p2->next();
        }
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    print_all(norse_gods);
    std::cout << '\n';

    print_all(greek_gods);
    std::cout << '\n';
}
