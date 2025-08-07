/*
Write a program that given a file name
and a word will output each line that contains that word together with the line number
Hint: getline()
*/

#include <fstream>
#include <iostream>

int main() {
    std::string file;
    std::string word;
    int line_counter = 0;
    std::string buffer;
    bool contains_word = false;
    std::cout << "Which file you you want to open: ";
    std::cin >> file;
    std::cout << "Which word are you looking for: ";
    std::cin >> word;
    std::ifstream ifs{file};
    if (!ifs) throw std::invalid_argument("Bad file name");
    while (getline(ifs, buffer)) {
        ++line_counter;
        if (buffer.contains(word)) {
            contains_word = true;
            std::println("Line: {}\nSentence: {}\nWord: {}", line_counter, buffer, word);
        }
    }
    if (!contains_word) std::cout << "Word not found" << '\n';
    return 0;
}
