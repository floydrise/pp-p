/*“ Reverse the order of characters in a text file. For example, asdfghjkl becomes lkjhgfdsa.
 *Warning: There is no really good, portable, and efficient way of reading a file backward.”*/

#include <fstream>
#include <iostream>

int main() {
    std::ifstream ifs{"to_be_reversed.txt"};
    std::ofstream ofs{"reversed.txt"};
    std::string buffer;
    std::string reverse;
    while (std::getline(ifs, buffer)) {
        for (int i = buffer.size() - 1; i >= 0; --i) {
            reverse += buffer[i];
        }
        ofs << reverse << '\n';
        std::cout << reverse << '\n';
    }
    std::cout << "Done";
    return 0;
}
