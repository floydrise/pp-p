#include <print>

int str_cmp(const char *s1, const char *s2) {
    if (s1 == nullptr || s2 == nullptr) return -1;

    while (*s1 != 0 && *s2 != 0) {
        if (*s1 < *s2) return -1;
        if (*s1 > *s2) return 1;
        s1++;
        s2++;
    }

    if (*s1 == 0 && *s2 == 0) return 0;
    if (*s1 == 0) return -1;
    return 1;
}


int main() {
    char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";

    // comparing strings str1 and str2
    int result = str_cmp(str1, str2);
    std::print("strcmp(str1, str2) = {}\n", result);

    // comparing strings str1 and str3
    result = str_cmp(str1, str3);
    std::print("strcmp(str1, str3) = {}\n", result);

    return 0;
}
