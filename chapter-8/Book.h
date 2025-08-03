//
// Created by Stefan Petrov on 3.08.25.
//

#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <chrono>


class Book {
public:
    Book(const std::string &title, const std::string &author, const std::string &ISBN,
         const std::chrono::year_month_day copyright_date): title(title), author(author), ISBN(ISBN),
                                                            copyright_date(copyright_date) {
        if (!(isdigit(ISBN[0]) && isdigit(ISBN[1]) && isdigit(ISBN[2]) && isalnum(ISBN[3])))
            throw
                    std::invalid_argument("ISBN should be nnnx - n is an int, x is a digit or letter");
    };

    std::string get_ISBN() const;

    std::string get_author() const;

    std::string get_title() const;

    std::string get_copyright_date() const;

    void set_check_out(bool val);

    bool is_checked_out() const;

private:
    std::string title;
    std::string ISBN;
    std::string author;
    std::chrono::year_month_day copyright_date{};
    bool checked_out = false;
};

bool operator==(const Book &first, const Book &second);

bool operator!=(const Book &first, const Book &second);

std::ostream &operator<<(std::ostream &os, const Book &book);

#endif //BOOK_H
