#include <iostream>

char *find_x(const char *s, const char *x) {
    const char *b = x;

    if (*b == 0) {
        return const_cast<char *>(s);
    }

    for (; *s != 0; ++s) {
        if (*s != *b) continue;

        const char *a = s;
        while (true) {
            if (*b == 0) return const_cast<char *>(s);
            if (*a++ != *b++) break;
        }
        b = x;
    }

    return nullptr;
};

int main() {
    char string[64] = "This is a test string for testing find_x()";
    char *p;

    p = find_x(string, "test");

    if (p) {
        std::print("String found:\nFirst occurrence of string \"test\" in \"{}\" is:\n{}", string, p);
    } else {
        printf("String not found!\n");
    }

    return 0;
}
