#include <iostream>

int main() {
    srand(time(nullptr));
    while (true) {
        char break_loop;
        const int rand_num = rand() % 3 + 1;
        std::string player;
        std::string computer;
        std::cout << "Enter rock, paper or scissors: ";
        std::cin >> player;
        std::transform(player.begin(), player.end(), player.begin(), tolower);
        if (player != "rock" && player != "paper" && player != "scissors") {
            std::cout << "Input not allowed!" << '\n';
            continue;
        }
        std::cout << "You entered: " << player << '\n';
        switch (rand_num) {
            case 1:
                computer = "rock";
                break;
            case 2:
                computer = "paper";
                break;
            case 3:
                computer = "scissors";
                break;
            default:
                computer = "rock";
                break;
        }
        std::cout << "Computer: " << computer << '\n';
        if (player == "rock" && computer == "scissors" ||
            player == "scissors" && computer == "paper" ||
            player == "paper" && computer == "rock") {
            std::cout << "You won!\n";
        } else if (player == computer) {
            std::cout << "Tie!\n";
        } else {
            std::cout << "You lost\n";
        }

        std::cout << "Do you wanna play again (y/n)? ";
        std::cin >> break_loop;
        if (break_loop == 'n') break;
    }
    return 0;
}
