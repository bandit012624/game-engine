// main.cpp
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include "Monster.h"
#include "Skills.h"

int main() {
    int playerHealth = 100;
    int maxHealth = 100;
    int playerLevel = 1;
    int playerXp = 0;
    int xpRequirement = 100;

    std::vector<std::string> playerInventory;
    SkillBook playerMagic; // Instantiate player spellbook

    std::vector<Monster> arenaHorde = {
        {"Goblin Scout", 40, 12, 'G', HEALTH_POTION},
        {"Orc Warrior", 75, 22, 'O', NONE},
        {"Cave Troll", 150, 40, 'T', IRON_SWORD}
    };

    Monster* activeTarget = nullptr;
    std::random_device seed;
    std::mt19937 generator(seed());

    std::cout << "=== ADVANCED GAME LOOP WITH ARSENAL INTERFACES ONLINE ===" << std::endl;

    std::string userInput = "-1";
    while (playerHealth > 0 && userInput != "0") {
        std::cout << "\n======================================" << std::endl;
        std::cout << "🏅 LEVEL: " << playerLevel << " | 📈 XP: " << playerXp << "/" << xpRequirement << std::endl;
        
        printStatusReport(playerHealth, playerMagic, arenaHorde, activeTarget, playerInventory);
        std::cin >> userInput;

        if (userInput == "0") continue;

        // --- COMMAND HASH: CONSUME POTION ROUTINE ---
        if (userInput == "u" || userInput == "U") {
            bool foundPotion = false;
            for (auto it = playerInventory.begin(); it != playerInventory.end(); ++it) {
                if (*it == "Health Potion") {
                    playerHealth += 40;
                    if (playerHealth > maxHealth) playerHealth = maxHealth;
                    std::cout << "\n🧪 [ITEM] Consumed Health Potion! Restored 40 HP." << std::endl;
                    playerInventory.erase(it);
                    foundPotion = true;
                    break;
                }
            }
            if (!foundPotion) std::cout << "\n❌ [ERROR] No items matching [Health Potion] discovered." << std::endl;
            continue;
        }

        // --- COMMAND HASH: MAGICAL SKILL SPELLCASTING ROUTINE ---
        if (userInput == "f" || userInput == "F") {
            if (activeTarget == nullptr || activeTarget->health <= 0) {
                std::cout << "\n❌ [SKILL] Cast Failed: You must lock onto a living target (1-3) first!" << std::endl;
                continue;
            }
            if (playerMagic.mana >= playerMagic.spellCost) {
                playerMagic.mana -= playerMagic.spellCost;
                
                std::cout << "\n🔥 [SKILL] You cast " << playerMagic.spellName << " at the " << activeTarget->name << "!" << std::endl;
                std::cout << "[SKILL] Magic hit registers absolute flat " << playerMagic.baseSpellDamage << " fire damage!" << std::endl;
                activeTarget->health -= playerMagic.baseSpellDamage;

                // Process Monster Death sequence following spell strike
                if (activeTarget->health <= 0) {
                    std::cout << "💀 [COMBAT] " << activeTarget->name << " vaporized by magical fires!" << std::endl;
                    if (activeTarget->dropItem == HEALTH_POTION) playerInventory.push_back("Health Potion");
                    else if (activeTarget->dropItem == IRON_SWORD) playerInventory.push_back("Iron Sword");

                    int rewardedXp = activeTarget->damage * 2; 
                    playerXp += rewardedXp;
                    if (playerXp >= xpRequirement) {
                        playerLevel++; playerXp -= xpRequirement; maxHealth += 25; playerHealth = maxHealth;
                        playerMagic.maxMana += 15; playerMagic.mana = playerMagic.maxMana; // Restore Mana on Level up
                        std::cout << "🌟 LEVEL UP! Reached Level " << playerLevel << "! Max HP/MP extended. 🌟\n" << std::endl;
                    }
                    activeTarget = nullptr;
                }
            } else {
                std::cout << "\n❌ [SKILL] Insufficient resource: Out of Mana points!" << std::endl;
            }
            continue;
        }

        // Convert standard structural inputs into matrix indexes
        int index = -1;
        try { index = std::stoi(userInput) - 1; } 
        catch (...) { std::cout << "\n❌ [ERROR] Unknown action matrix token." << std::endl; continue; }

        if (index >= 0 && index < arenaHorde.size()) {
            activeTarget = &arenaHorde[index];
            
            if (activeTarget->health > 0) {
                std::uniform_int_distribution<int> d20(1, 20);
                int hitRoll = d20(generator);

                std::uniform_int_distribution<int> playerRoll(15, 35);
                int baseDamage = playerRoll(generator);

                // --- WEAPON SYSTEM MODIFIER HOOK ---
                int weaponBonus = 0;
                for (const auto& item : playerInventory) {
                    if (item == "Iron Sword") {
                        weaponBonus = 15; // Grant +15 damage flat if tracking sword
                        break;
                    }
                }

                int totalDamage = baseDamage + weaponBonus;
                std::cout << "\n[DICE ROLL] You rolled a " << hitRoll << " on your D20!" << std::endl;

                if (hitRoll == 20) {
                    totalDamage *= 2;
                    std::cout << "✨ CRITICAL HIT! Double damage vectors applied! ✨" << std::endl;
                }

                if (weaponBonus > 0) {
                    std::cout << "⚔️ [WEAPON MASTER] Iron Sword applies a +15 attack bonus!" << std::endl;
                }

                std::cout << "[COMBAT] You strike the " << activeTarget->name << " for " << totalDamage << " damage!" << std::endl;
                activeTarget->health -= totalDamage;

                if (activeTarget->health <= 0) {
                    std::cout << "💀 [COMBAT] " << activeTarget->name << " collapses into dust!" << std::endl;
                    if (activeTarget->dropItem == HEALTH_POTION) playerInventory.push_back("Health Potion");
                    else if (activeTarget->dropItem == IRON_SWORD) playerInventory.push_back("Iron Sword");

                    int rewardedXp = activeTarget->damage * 2; 
                    playerXp += rewardedXp;
                    if (playerXp >= xpRequirement) {
                        playerLevel++; playerXp -= xpRequirement; maxHealth += 25; playerHealth = maxHealth;
                        playerMagic.maxMana += 15; playerMagic.mana = playerMagic.maxMana;
                        std::cout << "🌟 LEVEL UP! Reached Level " << playerLevel << "! Max HP/MP extended. 🌟\n" << std::endl;
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
                std::cout << "\n[COMBAT] Target has no remaining health allocations." << std::endl;
            }
        } else {
            std::cout << "\n[ERROR] Boundary overflow error." << std::endl;
        }
    }

    return 0;
}
