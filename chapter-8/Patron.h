//
// Created by Stefan Petrov on 4.08.25.
//

#ifndef PATRON_H
#define PATRON_H
#include <string>
#include <iostream>


class Patron {
public:
    Patron(std::string name, const std::string &card_num, int fees);

    [[nodiscard]] std::string get_name() const;

    [[nodiscard]] std::string get_card_num() const;

    [[nodiscard]] double get_fees() const;

    void set_fee(double new_fee);

    [[nodiscard]] bool owes_fee() const;

private:
    std::string name;
    std::string card_num; // format N-N-N-X
    double fees = 0;
};

std::ostream &operator<<(std::ostream &os, const Patron &patron);

#endif //PATRON_H
