// ❯ clang++ -std=c++23 foo.cppm --precompile -o foo.pcm
// ❯ clang++ -std=c++23 use.cpp -fmodule-file=foo=foo.pcm foo.pcm -o use

import foo;
#include <iostream>

int main() {
    print_foo();
    const int my_foo = get_foo();
    std::cout << my_foo << std::endl;
    set_foo(6);
    print_foo();
    return 0;
}
