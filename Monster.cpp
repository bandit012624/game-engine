// Monster.cpp
#include "Monster.h"
#include <iostream>

void printStatusReport(int playerHp, const std::vector<Monster>& horde, const Monster* target) {
    std::cout << "\n--------------------------------------" << std::endl;
    std::cout << "💖 PLAYER HP: " << playerHp << " HP" << std::endl;
    std::cout << "👾 ACTIVE HORDE CONFIGURATION: " << std::endl;

    for (int i = 0; i < horde.size(); i++) {
        // POINTER LOGIC: Check if the address of this specific monster matches our target pointer address
        if (target == &horde[i]) {
            std::cout << " 🎯 ==> "; // Draw an arrow if this monster is targeted
        } else {
            std::cout << "        ";
        }

        std::cout << "[" << i + 1 << "] " << horde[i].symbol << " " 
                  << horde[i].name << " -> Health: " << horde[i].health << " HP";
        if (horde[i].health <= 0) std::cout << " 💀 (FALLEN)";
        std::cout << std::endl;
    }
    std::cout << "\nEnter Target Number (1-3) to Select Target, or '0' to Quit: ";
}
