//
// Created by Stefan Petrov on 3.08.25.
//

#include <iostream>
#include "Book.h"

int main() try {
    Book my_book{
        "My new book", "Stefan", "000N",
        std::chrono::year_month_day{std::chrono::year(2001), std::chrono::month(3), std::chrono::day(22)}
    };
    Book my_second_book{
        "My new book", "Stefan", "000N",
        std::chrono::year_month_day{std::chrono::year(2001), std::chrono::month(3), std::chrono::day(22)}
    };;
    Book diff_book{
        "Diff Book", "John Doe", "001N",
        std::chrono::year_month_day{std::chrono::year(2001), std::chrono::month(3), std::chrono::day(22)}
    };
    auto author = my_book.get_author();
    auto isbn = my_book.get_ISBN();
    auto copyright_date = my_book.get_copyright_date();
    std::cout << my_book << std::endl;
    if (my_book == my_second_book) std::cout << "my_book == my_new_book" << std::endl;
    if (my_book != diff_book) std::cout << "my_book != diff_book" << std::endl;
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
}
