#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <limits>

void printSeparator() {
    std::cout << "----------------------------------------\n";
}

int getValidChoice() {
    int userChoice = 0;

    while (true) {
        std::cout << "Maak een keuze (1-3): ";

        if (!(std::cin >> userChoice)) {
            std::cout << "Ongeldige invoer. Voer een getal in.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (userChoice >= 1 && userChoice <= 3) return userChoice;
        else std::cout << "Kies een getal tussen 1 en 3.\n";
    }
}

void game() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        printSeparator();
        std::cout << "\nKies een optie:\n";
        std::cout << "1 - Steen\n";
        std::cout << "2 - Papier\n";
        std::cout << "3 - Schaar\n\n";

        int userChoice = getValidChoice();
        std::string userWordChoice = userChoice == 1 ? "Steen" : userChoice == 2 ? "Papier" : "Schaar";

        std::cout << "Jouw keuze: " << userWordChoice << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));

        int computerChoice = rand() % 3 + 1;
        std::string computerWordChoice = computerChoice == 1 ? "Steen" : computerChoice == 2 ? "Papier" : "Schaar";

        std::cout << "Bot's keuze: " << computerWordChoice << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "\n" << userWordChoice << " vs " << computerWordChoice << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (userChoice == computerChoice)std::cout << "\n<== Het is gelijkspel! ==>\n";
        else if ((userChoice == 1 && computerChoice == 3) || (userChoice == 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2))
            std::cout << "\n<== Jij hebt gewonnen! ==>\n";
        else std::cout << "\n<== De bot heeft gewonnen! ==>\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\nWil je nog een keer spelen? (j/n): ";
        std::string playAgain;
        std::cin >> playAgain;

        if (playAgain == "n" || playAgain == "nee") break;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    printSeparator();
    std::cout << "Bedankt voor het spelen!\n";
    printSeparator();
}

int main() {
    const std::string rules =
        "\nRegels van Steen-Papier-Schaar:\n"
        "--------------------------------\n"
        "Steen  wint van Schaar\n"
        "Papier wint van Steen\n"
        "Schaar wint van Papier\n"
        "Gelijke keuzes zijn gelijkspel\n";

    std::cout << rules;
    game();
    return 0;
}