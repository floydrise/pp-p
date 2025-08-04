//
// Created by Stefan Petrov on 4.08.25.
//

#include <iostream>
#include "Patron.h"

int main() {
    Patron new_patron{"Stefan", "000C", 0};
    std::cout << new_patron << std::endl;
    std::cout << "Owes fees: " << std::boolalpha << new_patron.owes_fee() << std::endl;
    std::cout << "Set fee to 10" << std::endl;
    new_patron.set_fee(10);
    std::cout << "Owes fees: " << std::boolalpha << new_patron.owes_fee() << std::endl;
    return 0;
}
