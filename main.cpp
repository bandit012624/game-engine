// main.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include "Monster.h" // Crucial: Imports your custom multi-file entity module!

int main() {
    int playerHealth = 100;
    int targetChoice = -1;

    std::vector<Monster> arenaHorde = {
        {"Goblin Scout", 40, 10, 'G'},
        {"Orc Warrior", 75, 20, 'O'},
        {"Cave Troll", 150, 35, 'T'}
    };

    std::cout << "=== MULTI-FILE ARCHITECTURE ENGINE ONLINE ===" << std::endl;

    while (playerHealth > 0 && targetChoice != 0) {
        printStatusReport(playerHealth, arenaHorde);
        std::cin >> targetChoice;

        if (targetChoice == 0) continue;

        int index = targetChoice - 1;
        if (index >= 0 && index < arenaHorde.size()) {
            if (arenaHorde[index].health > 0) {
                std::cout << "\n[COMBAT] You strike the " << arenaHorde[index].name << " for 30 damage!" << std::endl;
                arenaHorde[index].health -= 30;

                if (arenaHorde[index].health > 0) {
                    playerHealth -= arenaHorde[index].damage;
                }
            } else {
                std::cout << "\n[COMBAT] Target is already dead." << std::endl;
            }
        }
    }

    std::cout << "\n[STORAGE] Writing session statistics..." << std::endl;
    std::ofstream saveFile("log.txt");
    if (saveFile.is_open()) {
        saveFile << "=== MULTI-FILE COMPILE LOG ===" << std::endl;
        saveFile << "Final Player HP: " << playerHealth << std::endl;
        saveFile.close();
    }

    return 0;
}
