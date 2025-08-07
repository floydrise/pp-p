/*Write a program called multi_input.cpp that prompts the user to
 *enter several integers in any combination of octal, decimal, or hexadecimal,
 *using the 0 and 0x base prefixes;
 *interprets the numbers correctly; and converts them to decimal form. Then your program
 *should output the values in properly spaced columns like this:
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> integers;
    std::cout << "Enter integers using 0, 0x or no prefix, terminate with ';': ";
    std::string inp;

    while (std::cin >> inp && inp != ";") {
        integers.push_back(inp);
    }
    for (auto integer: integers) {
        if (integer[0] == '0' && integer[1] == 'x') {
            std::cout << integer << '\t' << "hexadecimal" << '\t' << "converts to" << '\t' << std::dec <<
                    std::stoi(integer, nullptr, 16) <<
                    '\t' <<
                    "decimal" << '\n';
        } else if (integer[0] == '0' && integer[1] != 'x') {
            std::cout << integer << '\t' << "octal" << "\t\t" << "converts to" << '\t' << std::dec <<
                    std::stoi(integer, nullptr, 8) <<
                    '\t' <<
                    "decimal" << '\n';
        } else {
            std::cout << integer << '\t' << "decimal" << "\t\t" << "converts to" << '\t' << std::dec <<
                    std::stoi(integer, nullptr, 10) <<
                    '\t' <<
                    "decimal" << '\n';
        }
    }
    return 0;
}
