#include <iostream>
#include <vector>

class Name_value {
public:
    std::string name;
    int value;
};

int main() {
    std::vector<Name_value> pairs;
    std::cout << "Write name-score values separated with space, write 'NoName 0' to exit: " << std::endl;

    try {
        while (true) {
            Name_value pair;
            std::cin >> pair.name >> pair.value;
            if (pair.name == "NoName" && pair.value == 0) break;
            for (auto [name, value]: pairs) {
                if (name == pair.name && value == pair.value)
                    throw std::invalid_argument(
                        "Name or value repeat!");
            }
            pairs.push_back(pair);
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Exception" << std::endl;
    }

    std::cout << "Pairs:" << std::endl;
    for (auto pair: pairs) {
        std::cout << pair.name << " " << pair.value << std::endl;
    }
    return 0;
}
