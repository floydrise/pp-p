#include <iostream>
#include <vector>

void print_array(std::ostream &os, const int *a, const int n) {
    for (int i = 0; i < n; ++i) {
        os << a[i] << std::endl;
    }
}

void print_vec(std::ostream &os, const std::vector<int> &vec) {
    for (const int val: vec) {
        os << val << std::endl;
    }
}

int main() {
    // initialise
    int *arr_ten = new int[10];
    int *arr_eleven = new int[11];
    int *arr_twenty = new int[20];
    std::vector<int> vec_ten(10);
    std::vector<int> vec_eleven(11);
    std::vector<int> vec_twenty(20);

    // fill
    for (int i = 0; i < 10; ++i) {
        arr_ten[i] = 100 + i;
    }
    for (int i = 0; i < 11; ++i) {
        arr_eleven[i] = 100 + i;
    }
    for (int i = 0; i < 20; ++i) {
        arr_twenty[i] = 100 + i;
    }
    for (int i = 0; i < vec_ten.size(); ++i) {
        vec_ten[i] = 100 + i;
    }
    for (int i = 0; i < vec_eleven.size(); ++i) {
        vec_eleven[i] = 100 + i;
    }
    for (int i = 0; i < vec_twenty.size(); ++i) {
        vec_twenty[i] = 100 + i;
    }

    // print
    std::cout << "Array ten elements: \n";
    print_array(std::cout, arr_ten, 10);
    std::cout << std::endl;
    std::cout << "Array eleven elements: \n";
    print_array(std::cout, arr_eleven, 11);
    std::cout << std::endl;
    std::cout << "Array twenty elements: \n";
    print_array(std::cout, arr_twenty, 20);
    std::cout << std::endl;
    std::cout << "Vector ten elements: \n";
    print_vec(std::cout, vec_ten);
    std::cout << std::endl;
    std::cout << "Vector eleven elements: \n";
    print_vec(std::cout, vec_eleven);
    std::cout << std::endl;
    std::cout << "Vector twenty elements: \n";
    print_vec(std::cout, vec_twenty);
    std::cout << std::endl;

    // delete
    delete[] arr_ten;
    delete[] arr_eleven;
    delete[] arr_twenty;
}
