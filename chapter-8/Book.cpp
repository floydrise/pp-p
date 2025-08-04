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

std::string Book::get_title() const {
    return title;
}

Genre Book::get_genre() const {
    return genre;
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

bool operator==(const Book &first, const Book &second) {
    return first.get_ISBN() == second.get_ISBN();
}

bool operator!=(const Book &first, const Book &second) {
    return first.get_ISBN() != second.get_ISBN();
}

std::ostream &operator<<(std::ostream &os, const Genre &genre) {
    std::string val;
    switch (genre) {
        case Genre::fiction:
            val = "Fiction";
            break;
        case Genre::biography:
            val = "Biography";
            break;
        case Genre::children:
            val = "Children";
            break;
        case Genre::nonfiction:
            val = "Nonfiction";
            break;
        case Genre::periodical:
            val = "Periodical";
            break;
        default:
            val = "No genre";
            break;
    }
    return os << val;
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    return os << "Title: " << book.get_title() << '\n' << "Author: " << book.get_author() << '\n' << "Genre: " << book.
           get_genre() << '\n' << "ISBN: " << book.get_ISBN() << std::endl;
}
