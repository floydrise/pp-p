//
// Created by Stefan Petrov on 4.08.25.
//

#include "Patron.h"

#include <iomanip>
#include <utility>

Patron::Patron(std::string name, const std::string &card_num, const int fees): name(std::move(name)),
                                                                               card_num(card_num),
                                                                               fees(fees) {
    if (!(isdigit(card_num[0]) && isdigit(card_num[1]) && isdigit(card_num[2]) && isalnum(card_num[3])))
        throw
                std::invalid_argument("Card number should be nnnx - n is an int, x is a digit or letter");
}

std::string Patron::get_name() const {
    return name;
}

std::string Patron::get_card_num() const {
    return card_num;
}

double Patron::get_fees() const {
    return fees;
}

void Patron::set_fee(const double new_fee) {
    if (new_fee < 0) throw std::invalid_argument("Fee can't be less than 0");
    fees = new_fee;
}

bool Patron::owes_fee() const {
    return fees > 0;
}


std::ostream &operator<<(std::ostream &os, const Patron &patron) {
    return os << "Name: " << patron.get_name() << '\n' << "Card number: " << patron.get_card_num() << '\n'
           << "Fees: " << std::fixed << std::setprecision(2) << patron.get_fees() << std::endl;
}
