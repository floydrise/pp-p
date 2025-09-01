#include <iostream>

#include "Link.h"

void print_all(Link *p) {
    std::cout << "{ ";
    while (p) {
        std::cout << p->value;
        if ((p = p->next))
            std::cout << ", ";
    }
    std::cout << " }";
}

int main() {
    Link *norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods, new Link{"Odin"});
    norse_gods = insert(norse_gods, new Link{"Zeus"});
    norse_gods = insert(norse_gods, new Link{"Freja"});

    Link *greek_gods = new Link{"Hera"};
    greek_gods = insert(greek_gods, new Link{"Athena"});
    greek_gods = insert(greek_gods, new Link{"Mars"});
    greek_gods = insert(greek_gods, new Link{"Poseidon"});

    Link *p = find(greek_gods, "Mars");
    if (p) {
        p->value = "Ares";
    }

    p = find(norse_gods, "Zeus");
    if (p) {
        if (p == norse_gods) {
            norse_gods = p->next;
        }
        erase(p);
        greek_gods = insert(greek_gods, p);
    }

    print_all(norse_gods);
    std::cout << '\n';

    print_all(greek_gods);
    std::cout << '\n';
}
