#include <iostream>

void to_lower(char *s) {
    while (*s != '\0') {
        if (*s >= 'A' && *s <= 'Z') *s = *s + 32;
        s++;
    }
}

int main() {
    char s[] = "Hello World!";
    to_lower(s);
    std::cout << s << std::endl;
}
