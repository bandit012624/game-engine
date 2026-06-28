// main.cpp
#include <iostream>
#include <vector>
#include <random> // Crucial: Imports the modern random number engines
#include "Monster.h"

int main() {
    int playerHealth = 100;
    int targetChoice = -1;

    std::vector<Monster> arenaHorde = {
        {"Goblin Scout", 40, 12, 'G'}, // Max damage 12
        {"Orc Warrior", 75, 22, 'O'},  // Max damage 22
        {"Cave Troll", 150, 40, 'T'}   // Max damage 40
    };

    Monster* activeTarget = nullptr;

    // --- RANDOM NUMBER GENERATOR SETUP ---
    // 1. Create a random device seed (gathers random noise from your hardware)
    std::random_device seed;
    // 2. Initialize the high-performance Mersenne Twister calculation engine
    std::mt19937 generator(seed());

    std::cout << "=== CORE ENGINE MODULES LINKED SUCCESSFULLY ===" << std::endl;

    while (playerHealth > 0 && targetChoice != 0) {
        printStatusReport(playerHealth, arenaHorde, activeTarget);
        std::cin >> targetChoice;

        if (targetChoice == 0) continue;

        int index = targetChoice - 1;
        if (index >= 0 && index < arenaHorde.size()) {
            activeTarget = &arenaHorde[index];
            
            if (activeTarget->health > 0) {
                // 3. DEFINE PLAYER DAMAGE RANGE (Roll anywhere from 15 to 35 damage)
                std::uniform_int_distribution<int> playerRoll(15, 35);
                int calculatedPlayerDmg = playerRoll(generator);

                std::cout << "\n[COMBAT] You slash the " << activeTarget->name 
                          << " for " << calculatedPlayerDmg << " damage!" << std::endl;
                activeTarget->health -= calculatedPlayerDmg;

                if (activeTarget->health > 0) {
                    // 4. DEFINE MONSTER DAMAGE RANGE (Roll from 1 up to their unique max attribute value)
                    std::uniform_int_distribution<int> monsterRoll(5, activeTarget->damage);
                    int calculatedMonsterDmg = monsterRoll(generator);

                    std::cout << "[COMBAT] The " << activeTarget->name << " counter-attacks you for " 
                              << calculatedMonsterDmg << " damage!" << std::endl;
                    playerHealth -= calculatedMonsterDmg;
                } else {
                    std::cout << "[COMBAT] " << activeTarget->name << " collapses into dust!" << std::endl;
                    activeTarget = nullptr; // Clear targeting pointer on death
                }
            } else {
                std::cout << "\n[COMBAT] Targeted entity is already dead." << std::endl;
            }
        } else {
            std::cout << "\n[ERROR] Targeting coordinate out of bounds." << std::endl;
        }
    }

    return 0;
}
