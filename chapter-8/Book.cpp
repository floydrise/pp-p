//
// Created by Stefan Petrov on 3.08.25.
//

#include "Book.h"

std::string Book::get_author() const {
    return author;
}

std::string Book::get_ISBN() const {
    return ISBN;
}

std::string Book::get_copyright_date() const {
    return std::format("{:02}/{:02}/{:04}",
                       static_cast<unsigned>(copyright_date.day()),
                       static_cast<unsigned>(copyright_date.month()),
                       static_cast<int>(copyright_date.year()));
}

bool Book::is_checked_out() const {
    return checked_out;
}

void Book::set_check_out(const bool val) {
    checked_out = val;
}
