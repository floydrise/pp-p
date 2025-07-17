#include <iostream>
#include <vector>

int main() {
    bool exit = false;
    int sum = 0;
    std::vector<std::pair<std::string, int> > pairs;
    std::vector<std::pair<std::string, int> > illegal_pairs;
    const std::vector<std::string> allowed_values = {
        "Monday", "monday", "mon",
        "Tuesday", "tuesday", "tue", "tues",
        "Wednesday", "wednesday", "wed",
        "Thursday", "thursday", "thu", "thur", "thurs",
        "Friday", "friday", "fri",
        "Saturday", "saturday", "sat",
        "Sunday", "sunday", "sun"
    };

    char ch;
    while (!exit) {
        std::cout << "Input day of the week, value pairs: " << std::endl;
        std::pair<std::string, int> tmp_pair;
        std::cin >> tmp_pair.first >> tmp_pair.second;

        bool valid = false;
        for (const auto &allowed_value: allowed_values) {
            if (tmp_pair.first == allowed_value) {
                valid = true;
                pairs.push_back(tmp_pair);
                break;
            }
        }
        if (!valid) {
            illegal_pairs.push_back(tmp_pair);
            std::cerr << "Invalid value: " << tmp_pair.first << std::endl;
        }

        std::cout << "Do you want to exit? (y/n): " << std::endl;
        std::cin >> ch;
        if (ch == 'y') exit = true;
    }
    std::cout << "Valid values: " << std::endl;
    for (const auto &[fst, snd]: pairs) {
        std::cout << fst << " " << snd << std::endl;
        sum += snd;
    }
    if (!illegal_pairs.empty()) {
        std::cout << "Invalid values:" << std::endl;
        for (const auto &[fst, snd]: illegal_pairs) {
            std::cout << fst << " " << snd << std::endl;
        }
    }
    std::cout << "Sum of valid values: " << sum << std::endl;
    std::cout << "Number of invalid values: " << illegal_pairs.size() << std::endl;

    return 0;
}
