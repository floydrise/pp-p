//
// Created by Stefan Petrov on 3.08.25.
//

#include <iostream>
#include "Book.h"

int main() try {
    // Initialisations
    Book my_book{
        "My new book", "Stefan", "000N",
        std::chrono::year_month_day{std::chrono::year(2001), std::chrono::month(3), std::chrono::day(22)},
        Genre{Genre::fiction}
    };
    Book my_second_book{
        "My new book", "Stefan", "000N",
        std::chrono::year_month_day{std::chrono::year(2001), std::chrono::month(3), std::chrono::day(22)},
        Genre{Genre::fiction}
    };;
    Book diff_book{
        "Diff Book", "John Doe", "001N",
        std::chrono::year_month_day{std::chrono::year(2001), std::chrono::month(3), std::chrono::day(22)},
        Genre{Genre::fiction}
    };

    // Test << operator overloading
    std::cout << my_book << std::endl;
    std::cout << "Books is checked out: " << std::boolalpha << my_book.is_checked_out() << std::endl;
    my_book.set_check_out(true);
    std::cout << "Books is checked out: " << std::boolalpha << my_book.is_checked_out() << std::endl;

    // Test == && != operators overloading
    if (my_book == my_second_book) std::cout << "my_book == my_new_book" << std::endl;
    if (my_book != diff_book) std::cout << "my_book != diff_book" << std::endl;
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
}
