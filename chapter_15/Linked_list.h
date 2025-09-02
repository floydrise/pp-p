// v2 of Link using "this" keyword

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <string>


class Linked_list {
public:
    std::string value;

    Linked_list(const std::pmr::string &v, Linked_list *p = nullptr, Linked_list *s = nullptr)
        : value{v}, prev{p}, succ{s} {
    }

    Linked_list *insert(Linked_list *n); // insert n before this object
    Linked_list *erase() const; // remove this object from list

    Linked_list *find(const std::string &s); // find s in list

    Linked_list *advance(int n); // move n positions in list
    Linked_list *next() const { return succ; }
    Linked_list *previous() const { return prev; }

private:
    Linked_list *prev;
    Linked_list *succ;
};


#endif //LINKED_LIST_H
