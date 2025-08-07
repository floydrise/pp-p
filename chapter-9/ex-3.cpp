#include <iostream>

/*Write a program that removes all vowels from a file (“disemvowels”). For example, Once upon a time! becomes nc pn tm!.
 *Surprisingly often, the result is still readable; try it on your friends.*/

int main() {
    std::string str = "Once upon a time!";
    std::string outp;
    for (char ch: str) {
        switch (std::tolower(ch)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                outp += "";
                break;
            default:
                outp += ch;
                break;
        }
    }
    std::cout << outp << '\n';
    return 0;
}
