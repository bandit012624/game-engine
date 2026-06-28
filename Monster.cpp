// Monster.cpp
#include "Monster.h" // Crucial: Connects this logic back to our header blueprint
#include <iostream>

void printStatusReport(int playerHp, const std::vector<Monster>& horde) {
    std::cout << "\n--------------------------------------" << std::endl;
    std::cout << "💖 PLAYER HP: " << playerHp << " HP" << std::endl;
    std::cout << "👾 ACTIVE HORDE CONFIGURATION: " << std::endl;

    for (int i = 0; i < horde.size(); i++) {
        std::cout << "   [" << i + 1 << "] " << horde[i].symbol << " " 
                  << horde[i].name << " -> Health: " << horde[i].health << " HP";
        if (horde[i].health <= 0) std::cout << " 💀 (FALLEN)";
        std::cout << std::endl;
    }
    std::cout << "\nEnter Target (1-3) or '0' to Quit and Save Log: ";
}
