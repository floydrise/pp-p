#include "Link.h"

Link *insert(Link *old_p, Link *new_p) {
    if (new_p == nullptr) // no new value to be added, return old value
        return old_p;
    if (old_p == nullptr) // nothing in the list, start a new list
        return new_p;
    new_p->next = old_p;
    if (old_p->prev)
        old_p->prev->next = new_p;
    new_p->prev = old_p->prev;
    old_p->prev = new_p;
    return new_p;
}

Link *erase(const Link *ptr) {
    if (ptr == nullptr) return nullptr;
    if (ptr->next) {
        ptr->next->prev = ptr->prev;
    }
    if (ptr->prev) {
        ptr->prev->next = ptr->next;
    }
    return ptr->next;
}

Link *find(Link *ptr, const std::string &str) {
    while (ptr) {
        if (ptr->value == str) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

Link *advance(Link *ptr, int n) {
    if (ptr == nullptr) return nullptr;
    while (n > 0) {
        --n;
        if (ptr->next)
            ptr = ptr->next;
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
