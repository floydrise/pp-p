#include <iostream>
#include "Name_pairs.h"

int main() {
    Name_pairs pairs{};
    pairs.read_names();
    pairs.read_ages();
    std::cout << "Unsorted:" << std::endl;
    std::cout << pairs << std::endl;
    pairs.sort();
    std::cout << "Sorted: " << std::endl;
    pairs.sort();
    std::cout << pairs << std::endl;
    return 0;
}
