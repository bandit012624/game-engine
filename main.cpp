// main.cpp
#include <iostream>
#include <vector>
#include "Monster.h"

int main() {
    int playerHealth = 100;
    int targetChoice = -1;

    std::vector<Monster> arenaHorde = {
        {"Goblin Scout", 40, 10, 'G'},
        {"Orc Warrior", 75, 20, 'O'},
        {"Cave Troll", 150, 35, 'T'}
    };

    // POINTER DECLARATION: Create an empty pointer pointing to no memory location
    Monster* activeTarget = nullptr;

    std::cout << "=== MEMORY POINTER TARGETING CORE ONLINE ===" << std::endl;

    while (playerHealth > 0 && targetChoice != 0) {
        // Pass our activeTarget pointer into our status renderer function
        printStatusReport(playerHealth, arenaHorde, activeTarget);
        std::cin >> targetChoice;

        if (targetChoice == 0) continue;

        int index = targetChoice - 1;
        if (index >= 0 && index < arenaHorde.size()) {
            // POINTER ASSIGNMENT: Lock our pointer onto the exact memory address of the chosen monster
            activeTarget = &arenaHorde[index];
            
            std::cout << "\n[ENGINE] Target locked onto memory address: " << activeTarget << std::endl;
            
            // POINTER ACCESS: To read data through a pointer, we use the arrow '->' operator
            if (activeTarget->health > 0) {
                std::cout << "[COMBAT] Attacking " << activeTarget->name << " through pointer link!" << std::endl;
                activeTarget->health -= 20;
            } else {
                std::cout << "[COMBAT] Targeted object contains zero health." << std::endl;
            }
        } else {
            std::cout << "\n[ERROR] Targeting coordinate out of bounds." << std::endl;
        }
    }

    return 0;
}
