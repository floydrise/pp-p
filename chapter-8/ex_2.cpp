#include <algorithm>
#include <iostream>
#include <vector>

class Name_pairs {
public:
    Name_pairs() {
    };

    void read_names();

    void read_ages();

    void print() const;

    void sort();

private:
    std::vector<std::string> name;
    std::vector<double> age;
};

void Name_pairs::read_names() {
    std::string inp;
    std::cout << "Input names and type 'quit' to end: " << std::endl;
    while (std::cin >> inp && inp != "quit") {
        name.push_back(inp);
    }
}

void Name_pairs::read_ages() {
    double inp = 0;
    if (name.size() == 0) {
        std::cerr << "No names, input names first" << std::endl;
        return;
    };
    for (auto value: name) {
        std::cout << "Input age for " << value << ": ";
        std::cin >> inp;
        age.push_back(inp);
    }
}

void Name_pairs::print() const {
    std::cout << "The pairs are:" << std::endl;
    for (int i = 0; i < name.size(); ++i) {
        std::cout << name[i] << ": " << age[i] << std::endl;
    }
}

void Name_pairs::sort() {
    std::vector<std::pair<std::string, double> > name_age_pair;
    for (int i = 0; i < name.size(); ++i) {
        name_age_pair.push_back({name[i], age[i]});
    }
    std::sort(name_age_pair.begin(), name_age_pair.end());

    for (int i = 0; i < name.size(); ++i) {
        name[i] = name_age_pair[i].first;
        age[i] = name_age_pair[i].second;
    }
}

int main() {
    Name_pairs pairs{};
    pairs.read_names();
    pairs.read_ages();
    std::cout << "Unsorted:" << std::endl;
    pairs.print();
    pairs.sort();
    std::cout << "Sorted: " << std::endl;
    pairs.sort();
    pairs.print();
    return 0;
}
