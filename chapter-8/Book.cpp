//
// Created by Stefan Petrov on 3.08.25.
//

#include "Book.h"

Book::Book(std::string title, std::string author, const std::string &ISBN,
           const std::chrono::year_month_day copyright_date, const Genre &genre) : title(std::move(title)), ISBN(ISBN),
    author(std::move(author)),
    copyright_date(copyright_date), genre(genre) {
    if (!(isdigit(ISBN[0]) && isdigit(ISBN[1]) && isdigit(ISBN[2]) && isalnum(ISBN[3])))
        throw
                std::invalid_argument("ISBN should be nnnx - n is an int, x is a digit or letter");
};


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
