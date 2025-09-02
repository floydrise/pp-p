//
// Created by Stefan Petrov on 1.09.25.
//

#ifndef LINK_H
#define LINK_H
#include <string>
#include <utility>

struct Link {
    explicit Link(std::string title, Link *p = nullptr, Link *n = nullptr): value(std::move(title)), prev(p), next(n) {
    };

    ~Link() = default;

    std::string value;
    Link *prev;
    Link *next;
};

Link *insert(Link *old_p, Link *new_p);

Link *erase(const Link *ptr); // remove ptr from list, return ptr->next

Link *find(Link *ptr, const std::string &str); // find str in list, return nullptr for "not found"

Link *advance(Link *ptr, int n);

// move n positions in list, return nullptr for "not found"
// positive n moves forward, negative n moves backwards


#endif //LINK_H
