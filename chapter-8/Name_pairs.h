//
// Created by Stefan Petrov on 3.08.25.
//

#ifndef NAME_PAIRS_H
#define NAME_PAIRS_H

#include <iostream>
#include <vector>

class Name_pairs {
public:
    Name_pairs() {
    };

    void read_names();

    void read_ages();

    std::vector<std::string> get_names();

    std::vector<double> get_ages();

    void print() const;

    void sort();

private:
    std::vector<std::string> name;
    std::vector<double> age;
};

std::ostream &operator<<(std::ostream &os, Name_pairs &np);

bool operator==(Name_pairs &first, Name_pairs &second);

bool operator!=(Name_pairs &first, Name_pairs &second);

#endif //NAME_PAIRS_H
