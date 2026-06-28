#include <iostream>
#include <vector> // Imports the dynamic array module

void printStatusReport(int health, const std::vector<int>& monsters) {
    std::cout << "\n--------------------------------------" << std::endl;
    std::cout << "💖 PLAYER HP: " << health << " HP" << std::endl;
    
    std::cout << "👾 ENEMIES IN ARENA: " << std::endl;
    // A 'for' loop that automatically iterates through our entire vector array
    for (int i = 0; i < monsters.size(); i++) {
        std::cout << "   -> Enemy [" << i + 1 << "]: " << monsters[i] << " HP";
        if (monsters[i] <= 0) {
            std::cout << " 💀 (DEFEATED)";
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nEnter Action (a = Attack Target 1, d = Defend, q = Quit): ";
}

int main() {
    int playerHealth = 100;
    char userChoice = ' ';

    // CREATING A VECTOR ARRAY
    // This instantiates a list containing 3 enemies with 50, 30, and 80 health points
    std::vector<int> arenaMonsters = {50, 30, 80};

    std::cout << "=== MULTI-ENTITY ENGAGEMENT ENGINE BOOTED ===" << std::endl;

    while (playerHealth > 0 && userChoice != 'q') {
        
        printStatusReport(playerHealth, arenaMonsters);
        std::cin >> userChoice;

        if (userChoice == 'a') {
            // Target the first enemy in our vector list (index 0 is the 1st slot!)
            if (arenaMonsters[0] > 0) {
                std::cout << "[COMBAT] You strike Enemy 1 for 25 damage!" << std::endl;
                arenaMonsters[0] -= 25;
            } else {
                std::cout << "[COMBAT] You slash wildly at thin air! Enemy 1 is already dead!" << std::endl;
            }
            
            std::cout << "[COMBAT] The remaining horde retaliates! You take 15 damage." << std::endl;
            playerHealth -= 15;
        } 
        else if (userChoice == 'd') {
            std::cout << "[COMBAT] Shield braced! You successfully mitigate incoming mob damage." << std::endl;
        } 
        else if (userChoice == 'q') {
            std::cout << "[ENGINE] Initiating system teardown sequence." << std::endl;
        } 
        else {
            std::cout << "[ERROR] Input mismatch. You take 5 attrition damage." << std::endl;
            playerHealth -= 5;
        }
    }

    std::cout << "\n======================================" << std::endl;
    if (playerHealth <= 0) {
        std::cout << "💀 playerHealth depleted. GAME OVER. 💀" << std::endl;
    } else {
        std::cout << "👋 Sandbox execution terminated successfully. 👋" << std::endl;
    }

    return 0;
}
