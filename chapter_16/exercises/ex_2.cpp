#include <iostream>

char *str_dup(const char *s) {
    int len = 0;
    while (s[len] != '\0') ++len;
    char *cpy = new char[len + 1];
    for (int i = 0; i <= len; ++i) {
        cpy[i] = s[i];
    }
    return cpy;
};

int main() {
    char str[] = "test";
    char *cpy = str_dup(str);
    std::cout << cpy << std::endl;
    delete[] cpy;
}
