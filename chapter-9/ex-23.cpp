/*Write a program that accepts two file names and produces a new file that is the contents of the first file followed
 *by the contents of the second; that is, the program concatenates the two files.*/

#include <fstream>
#include <iostream>

int main() {
    std::ifstream ifs_to_be_reversed{"to_be_reversed.txt"};
    std::ifstream ifs_reversed{"reversed.txt"};
    std::ofstream ofs_output{"ex_23_output.txt"};
    std::string buffer;
    while (std::getline(ifs_to_be_reversed, buffer)) {
        ofs_output << buffer << '\n';
    }
    while (getline(ifs_reversed, buffer)) {
        ofs_output << buffer << '\n';
    }
    return 0;
}
