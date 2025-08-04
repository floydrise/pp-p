//
// Created by Stefan Petrov on 3.08.25.
//

#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <chrono>
#include <utility>

enum class Genre { fiction, nonfiction, periodical, biography, children };

class Book {
public:
    Book(std::string title, std::string author, const std::string &ISBN,
         std::chrono::year_month_day copyright_date, const Genre &genre);

    [[nodiscard]] std::string get_ISBN() const;

    [[nodiscard]] std::string get_author() const;

    [[nodiscard]] std::string get_title() const;

    [[nodiscard]] std::string get_copyright_date() const;

    [[nodiscard]] Genre get_genre() const;

    void set_check_out(bool val);

    [[nodiscard]] bool is_checked_out() const;

private:
    std::string title;
    std::string ISBN;
    std::string author;
    std::chrono::year_month_day copyright_date{};
    Genre genre;
    bool checked_out = false;
};

bool operator==(const Book &first, const Book &second);

bool operator!=(const Book &first, const Book &second);

std::ostream &operator<<(std::ostream &os, const Book &book);

#endif //BOOK_H
