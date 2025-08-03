//
// Created by Stefan Petrov on 3.08.25.
//

#include <iostream>
#include "Book.h"

int main() try {
    Book my_book{
        "000N", "Stefan",
        std::chrono::year_month_day{std::chrono::year(2001), std::chrono::month(3), std::chrono::day(22)}
    };;
    auto author = my_book.get_author();
    auto isbn = my_book.get_ISBN();
    std::string copyright_date = my_book.get_copyright_date();

    std::cout << "Author: " << author << '\n' << "ISBN: " << isbn << '\n' << "Copyright date: " << copyright_date <<
            std::endl;
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
}
