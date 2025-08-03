#include <iostream>
#include "Name_pairs.h"

int main() {
    Name_pairs pairs{};
    Name_pairs second{};
    std::cout << "Input first pairs:" << std::endl;
    pairs.read_names();
    pairs.read_ages();
    std::cout << "Input second pairs:" << std::endl;
    second.read_names();
    second.read_ages();
    std::cout << "First pairs sorted:" << std::endl;
    pairs.sort();
    std::cout << pairs << std::endl;
    std::cout << "Second pairs sorted: " << std::endl;
    second.sort();
    std::cout << second << std::endl;
    std::cout << "Bool operator overload" << std::endl;
    if (pairs == second) std::cout << "true" << std::endl;
    if (pairs != second) std::cout << "false" << std::endl;
    return 0;
}
