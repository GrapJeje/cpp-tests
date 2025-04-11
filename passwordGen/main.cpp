#include <iostream>
#include <string>
#include <random>

const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const std::string special_chars = "!@#$%^&*()_+-=~`";
std::string generate_password(int length) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> char_dist(0, chars.length() - 1);
    std::uniform_int_distribution<> special_dist(0, special_chars.length() - 1);
    std::uniform_real_distribution<> prob_dist(0.0, 1.0);

    std::string password;
    for (int i = 0; i < length; i++) {
        if (prob_dist(gen) < 0.4) password += special_chars[special_dist(gen)];
        else password += chars[char_dist(gen)];
    }
    return password;
}

int main() {
    std::cout << "Hoe lang wil je je wachtwoord hebben? ";
    int passwordLength;

    if (!(std::cin >> passwordLength) || passwordLength < 1) {
        std::cout << "Ongeldige invoer. Voer een positief getal in." << std::endl;
        return 1;
    }

    std::cout << "Je wachtwoord is: " << generate_password(passwordLength) << std::endl;
    return 0;
}