//
// Created by Stefan Petrov on 3.08.25.
//

#include "Name_pairs.h"
#include <algorithm>

void Name_pairs::read_names() {
    std::string inp;
    std::cout << "Input names and type 'quit' to end: " << std::endl;
    while (std::cin >> inp && inp != "quit") {
        name.push_back(inp);
    }
}

std::vector<std::string> Name_pairs::get_names() {
    return name;
}

std::vector<double> Name_pairs::get_ages() {
    return age;
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

std::ostream &operator<<(std::ostream &os, Name_pairs &np) {
    const std::vector<std::string> name_vals = np.get_names();
    const std::vector<double> age_vals = np.get_ages();
    std::string tmp;
    for (int i = 0; i < name_vals.size(); ++i) {
        tmp += name_vals[i] + ": " + std::to_string(static_cast<int>(age_vals[i])) + '\n';
    }
    return os << tmp << std::endl;
}

