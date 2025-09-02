#include <iostream>

int main() {
    // C style
    int *int_p = (int *) (malloc(4 * sizeof(int)));
    for (int i = 0; i < 4; ++i) {
        int_p[i] = i;
        printf("%p\n", (void *) (int_p + i));
        printf("%d\n", *(int_p + i));
    }
    free(int_p);

    // C++ style
    int *ptr = new int[4];
    for (int i = 0; i < 4; ++i) {
        ptr[i] = i;
        std::print("{}\n", ptr[i]); // C++23 only
    }
    delete[] ptr;

    // new C++ style
    auto new_ptr = std::make_unique<int[]>(4);
    for (int i = 0; i < 4; ++i) {
        new_ptr[i] = i;
        std::print("{}\n", new_ptr[i]);
    }
    return 0;
}
