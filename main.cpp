// main.cpp
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include "Monster.h"

int main() {
    int playerHealth = 100;
    int maxHealth = 100;
    int playerLevel = 1;
    int playerXp = 0;
    int xpRequirement = 100;

    // PLAYER INVENTORY BACKPACK
    std::vector<std::string> playerInventory;

    // Setup monsters with specific item drops attached to their profiles
    std::vector<Monster> arenaHorde = {
        {"Goblin Scout", 40, 12, 'G', HEALTH_POTION},
        {"Orc Warrior", 75, 22, 'O', NONE},
        {"Cave Troll", 150, 40, 'T', IRON_SWORD}
    };

    Monster* activeTarget = nullptr;
    std::random_device seed;
    std::mt19937 generator(seed());

    std::cout << "=== ENGINE PROGRESSION & INVENTORY MODULES ONLINE ===" << std::endl;

    std::string userInput = "-1";
    while (playerHealth > 0 && userInput != "0") {
        std::cout << "\n======================================" << std::endl;
        std::cout << "🏅 LEVEL: " << playerLevel << " | 📈 XP: " << playerXp << "/" << xpRequirement << std::endl;
        
        printStatusReport(playerHealth, arenaHorde, activeTarget, playerInventory);
        std::cin >> userInput;

        // Process exit code
        if (userInput == "0") continue;

        // --- INVENTORY ITEM USAGE HOOK ---
        if (userInput == "u" || userInput == "U") {
            bool foundPotion = false;
            // Search the backpack array for a potion
            for (auto it = playerInventory.begin(); it != playerInventory.end(); ++it) {
                if (*it == "Health Potion") {
                    playerHealth += 40;
                    if (playerHealth > maxHealth) playerHealth = maxHealth;
                    std::cout << "\n🧪 [ITEM] You drank a Health Potion! Restored 40 HP." << std::endl;
                    playerInventory.erase(it); // Remove the consumed potion from your backpack vector
                    foundPotion = true;
                    break;
                }
            }
            if (!foundPotion) {
                std::cout << "\n❌ [ERROR] You don't have any Health Potions in your backpack!" << std::endl;
            }
            continue;
        }

        // Convert user selection string into target index
        int index = -1;
        try {
            index = std::stoi(userInput) - 1; // Parse string integer
        } catch (...) {
            std::cout << "\n❌ [ERROR] Invalid action command." << std::endl;
            continue;
        }

        if (index >= 0 && index < arenaHorde.size()) {
            activeTarget = &arenaHorde[index];
            
            if (activeTarget->health > 0) {
                std::uniform_int_distribution<int> d20(1, 20);
                int hitRoll = d20(generator);

                std::uniform_int_distribution<int> playerRoll(15, 35);
                int calculatedPlayerDmg = playerRoll(generator);

                std::cout << "\n[DICE ROLL] You rolled a " << hitRoll << " on your D20!" << std::endl;

                if (hitRoll == 20) {
                    calculatedPlayerDmg *= 2;
                    std::cout << "✨ CRITICAL HIT! Double damage applied! ✨" << std::endl;
                }

                std::cout << "[COMBAT] You slash the " << activeTarget->name << " for " << calculatedPlayerDmg << " damage!" << std::endl;
                activeTarget->health -= calculatedPlayerDmg;

                // --- MONSTER DEFEATED EVENT ---
                if (activeTarget->health <= 0) {
                    std::cout << "💀 [COMBAT] " << activeTarget->name << " collapses into dust!" << std::endl;
                    
                    // 1. Process Item Drop
                    if (activeTarget->dropItem == HEALTH_POTION) {
                        playerInventory.push_back("Health Potion");
                        std::cout << "🎁 [LOOT DROP] The Goblin dropped a shiny vial! Added [Health Potion] to inventory." << std::endl;
                    } else if (activeTarget->dropItem == IRON_SWORD) {
                        playerInventory.push_back("Iron Sword");
                        std::cout << "🎁 [LOOT DROP] The Troll dropped a massive blade! Added [Iron Sword] to inventory." << std::endl;
                    }

                    // 2. Process Experience points
                    int rewardedXp = activeTarget->damage * 2; 
                    playerXp += rewardedXp;
                    std::cout << "🎉 [XP GAIN] You earned " << rewardedXp << " experience points!" << std::endl;

                    if (playerXp >= xpRequirement) {
                        playerLevel += 1;
                        playerXp -= xpRequirement;
                        maxHealth += 25;
                        playerHealth = maxHealth;
                        std::cout << "\n🌟 LEVEL UP! Reached Level " << playerLevel << "! Max HP extended to " << maxHealth << " HP. 🌟\n" << std::endl;
                    }

                    activeTarget = nullptr;
                } 
                else {
                    std::uniform_int_distribution<int> monsterRoll(5, activeTarget->damage);
                    int calculatedMonsterDmg = monsterRoll(generator);

                    std::cout << "[COMBAT] The " << activeTarget->name << " counter-attacks you for " << calculatedMonsterDmg << " damage!" << std::endl;
                    playerHealth -= calculatedMonsterDmg;
                }
            } else {
                std::cout << "\n[COMBAT] Targeted entity contains zero health assets." << std::endl;
            }
        } else {
            std::cout << "\n[ERROR] Target out of structural limits." << std::endl;
        }
    }

    return 0;
}
