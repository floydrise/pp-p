#include <iostream>

int main() {
    std::vector<std::string> names;
    std::vector<int> scores;

    while (true) {
        std::string inp_name;
        int inp_score = 0;
        std::cout << "Input name and score separated with space: ";
        std::cin >> inp_name >> inp_score;
        if (inp_name == "NoName" && inp_score == 0) break;
        bool name_exists = false;
        for (std::string name: names) {
            if (inp_name == name) {
                std::cout << "Name already exists, terminating loop!" << '\n';
                name_exists = true;
                break;
            }
        }
        if (name_exists) break;
        names.push_back(inp_name);
        scores.push_back(inp_score);
    }

    while (true) {
        std::string inp_val;
        char answer;
        std::vector<int> indices;
        std::cout << "Enter a value and I'll give you the names: ";
        std::cin >> inp_val;

        for (int i = 0; i < scores.size(); ++i) {
            if (std::stoi(inp_val) == scores[i]) {
                indices.push_back(i);
            }
        }

        if (indices.size() == 0) {
            std::cout << "Score not found\n";
            continue;
        }

        for (const int index: indices) {
            std::cout << names[index] << " ";
        }

        std::cout << "\nDo you want to exit (y/n)? ";
        std::cin >> answer;
        if (answer == 'y') break;
    }

    return 0;
}
