// Below is the solution with one word

/*
#include <iostream>

int main() {
    std::string disliked = "Broccoli";
    std::vector<std::string> dictionary;

    for (std::string inp; std::cin >> inp;) {
        dictionary.push_back(inp);
    }

    for (int i = 0; i < dictionary.size(); ++i) {
        if (dictionary[i] == disliked) {
            std::cout << "BLEEP" << '\n';
        } else {
            std::cout << dictionary[i] << '\n';
        }
    }

    return 0;
}
*/


// below is the solution with multiple disliked words
#include <iostream>

int main() {
    const std::vector<std::string> disliked = {"Broccoli", "disliked", "test"};
    std::vector<std::string> dictionary;

    // example test input list: word Broccoli my disliked haha test
    std::cout << "Input a word list separated with space: ";
    for (std::string inp; std::cin >> inp;) {
        dictionary.push_back(inp);
    }

    // nested loops have not been covered in the book yet, but this is a decent, simple solution
    // an easier solution will be if the dictionary is mutated -> dictionary[i] == disliked[j]
    // and then print everything, but we lose the original input this way
    std::cout << "\nBleeped list:" << '\n';
    for (int i = 0; i < dictionary.size(); ++i) {
        bool isBleep = false;
        for (int j = 0; j < disliked.size(); j++) {
            if (dictionary[i] == disliked[j]) {
                std::cout << "BLEEP" << '\n';
                isBleep = true;
                break;
            }
        }
        if (!isBleep)
            std::cout << dictionary[i] << '\n';
    }

    std::cout << "\nOriginal list:" << '\n';
    for (const std::string &basic_string: dictionary) {
        std::cout << basic_string << '\n';
    }

    return 0;
}
