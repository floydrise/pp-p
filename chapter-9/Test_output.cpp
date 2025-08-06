#include <fstream>
#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

std::ostream &operator<<(std::ostream &os, Point &p) {
    return os << "x: " << p.x << '\t' << "y: " << p.y;
}

std::istream &operator>>(std::istream &is, Point &p) {
    return is >> p.x >> p.y;
}

bool operator==(const std::vector<Point> &a, const std::vector<Point> &b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].x != b[i].x || a[i].y != b[i].y) return false;
    }
    return true;
}

void input_points(std::vector<Point> &vec_points) {
    std::cout << "Input points:\n";
    for (int i = 0; i < 7; ++i) {
        Point point{};
        std::cin >> point;
        vec_points.push_back(point);
    }
}

int main() {
    /*
    constexpr int birth_year = 1999;
    constexpr int age = 26;
    double dbl = 1234567.89;


    std::cout << "Dec: " << '\t' << "Hex: " << '\t' << "Oct: " << std::endl;
    std::cout << std::dec << birth_year << '\t' << std::hex << birth_year << '\t' << std::oct << birth_year <<
            std::endl;
    std::cout << std::dec << age << '\t' << std::hex << age << '\t' << std::oct << age <<
            std::endl;

    std::cout << std::format("Default: {}, Fixed: {:f}, Scientific: {:e}\n", dbl, dbl, dbl);
    */


    std::vector<Point> original_points;
    std::vector<Point> processed_points;

    input_points(original_points);

    std::ofstream ofs{"mydata.txt"};
    for (auto [x, y]: original_points) {
        ofs << x << " " << y << '\n';
    }
    ofs.close();


    std::ifstream ifs{"mydata.txt"};
    Point tmp{};

    while (ifs >> tmp)
        processed_points.push_back(tmp);

    std::cout << "Original points vector values:\n";
    for (auto original_point: original_points) {
        std::cout << original_point << std::endl;
    }

    std::cout << "Processed point vector values:\n";
    for (auto processed_point: processed_points) {
        std::cout << processed_point << std::endl;
    }

    if (original_points != processed_points) std::cerr << "Something's wrong!" << std::endl;

    return 0;
}
