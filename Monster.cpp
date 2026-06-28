// Monster.cpp
#include "Monster.h"
#include <iostream>

void printStatusReport(int playerHp, const SkillBook& magic, const std::vector<Monster>& horde, const Monster* target, const std::vector<std::string>& inventory) {
    std::cout << "\n--------------------------------------" << std::endl;
    std::cout << "💖 PLAYER HP: " << playerHp << " HP" << std::endl;
    printManaBar(magic); // Call our inline skill book renderer
    
    std::cout << "🎒 INVENTORY: ";
    if (inventory.empty()) {
        std::cout << "[Empty]";
    } else {
        for (const auto& item : inventory) {
            std::cout << "[" << item << "] ";
        }
    }
    std::cout << "\n--------------------------------------" << std::endl;

    std::cout << "👾 ACTIVE HORDE CONFIGURATION: " << std::endl;
    for (int i = 0; i < horde.size(); i++) {
        if (target == &horde[i]) std::cout << " 🎯 ==> ";
        else std::cout << "        ";

        std::cout << "[" << i + 1 << "] " << horde[i].symbol << " " 
                  << horde[i].name << " -> Health: " << horde[i].health << " HP";
        if (horde[i].health <= 0) std::cout << " 💀 (FALLEN)";
        std::cout << std::endl;
    }
    std::cout << "\nEnter Command (1-3 to Attack, 'f' for Fireball, 'u' for Potion, '0' to Quit): ";
}
