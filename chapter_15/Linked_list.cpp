//
// Created by Stefan Petrov on 2.09.25.
//

#include "Linked_list.h"

Linked_list *Linked_list::insert(Linked_list *n) // insert n before p; return n
{
    if (n == nullptr)
        return this;
    n->succ = this; // this object comes after n
    if (prev)
        prev->succ = n;
    n->prev = prev; // this object’s predecessor becomes n’s predecessor
    prev = n; // n becomes this object’s predecessor
    return n;
}

Linked_list *Linked_list::erase() const {
    if (succ) {
        succ->prev = prev;
    }
    if (prev) {
        prev->succ = succ;
    }
    return succ;
}

Linked_list *Linked_list::find(const std::string &s) {
    Linked_list *ptr = this;
    while (ptr) {
        if (ptr->value == s) return ptr;
        ptr = succ;
    }
    return nullptr;
}

Linked_list *Linked_list::advance(int n) {
    Linked_list *ptr = this;
    if (ptr == nullptr) return nullptr;
    while (n > 0) {
        --n;
        if (ptr->succ)
            ptr = ptr->succ;
        else
            return nullptr;
    }
    while (n < 0) {
        ++n;
        if (ptr->prev)
            ptr = ptr->prev;
        else
            return nullptr;
    }
    return ptr;
}
