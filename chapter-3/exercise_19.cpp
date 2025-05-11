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
        std::string inp_name;
        char answer;
        int index = -1;
        std::cout << "Enter a name and I'll give you the score: ";
        std::cin >> inp_name;

        for (int i = 0; i < names.size(); ++i) {
            if (inp_name == names[i]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            std::cout << "Name not found\n";
            continue;
        }

        std::cout << names[index] << " " << scores[index] << '\n';

        std::cout << "Do you want to exit (y/n)? ";
        std::cin >> answer;
        if (answer == 'y') break;
    }

    return 0;
}
