#include <iostream>

char *cat_dot(const char *s1, const char *s2) {
    // get length
    int s1_len = 0;
    int s2_len = 0;
    for (const char *p = s1; *p; ++p) s1_len++;
    for (const char *p = s2; *p; ++p) s2_len++;

    // declare pointers
    char *str = new char[s1_len + s2_len + 2];
    char *ptr = str;

    // copy first string
    while (*s1) *ptr++ = *s1++;

    // add dot
    *ptr++ = '.';

    // copy second string
    while (*s2) *ptr++ = *s2++;

    // add terminating zero
    *ptr++ = 0;

    return str;
}

int main() {
    constexpr char s1[] = "Niels";
    constexpr char s2[] = "Bohr";

    const char *val = cat_dot(s1, s2);

    std::cout << val << '\n';
    delete[] val;
}
