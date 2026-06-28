#include <iostream>
#include <vector>
#include <string> // Lets us use standard text words for names

// 1. THE DATA BLUEPRINT: Defining what a Monster is
struct Monster {
    std::string name;
    int health;
    int damage;
    char symbol;
};

// 2. THE STATUS MONITOR FUNCTION
void printStatusReport(int playerHp, const std::vector<Monster>& horde) {
    std::cout << "\n--------------------------------------" << std::endl;
    std::cout << "💖 PLAYER HP: " << playerHp << " HP" << std::endl;
    std::cout << "👾 ACTIVE HORDE CONFIGURATION: " << std::endl;

    for (int i = 0; i < horde.size(); i++) {
        std::cout << "   [" << i + 1 << "] " << horde[i].symbol << " " 
                  << horde[i].name << " -> Health: " << horde[i].health << " HP | Atk: " 
                  << horde[i].damage << " DMG";
        
        if (horde[i].health <= 0) {
            std::cout << " 💀 (FALLEN)";
        }
        std::cout << std::endl;
    }
    std::cout << "\nEnter Target Number to Attack (1-3) or '0' to Quit: ";
}

// 3. MAIN RUNTIME PIPELINE
int main() {
    int playerHealth = 100;
    int targetChoice = -1;

    // INSTANTIATING OBJECTS FROM OUR BLUEPRINT
    // We populate our dynamic vector directly with custom Monster entities
    std::vector<Monster> arenaHorde = {
        {"Goblin Scout", 40, 10, 'G'},
        {"Orc Warrior", 75, 20, 'O'},
        {"Cave Troll", 150, 35, 'T'}
    };

    std::cout << "=== OBJECT-ORIENTED ARENA ENGINE RUNNING ===" << std::endl;

    while (playerHealth > 0 && targetChoice != 0) {
        printStatusReport(playerHealth, arenaHorde);
        std::cin >> targetChoice;

        // Process exit code
        if (targetChoice == 0) {
            std::cout << "[ENGINE] Received terminal shutdown instruction." << std::endl;
            continue;
        }

        // Convert user selection (1-3) into vector memory indexes (0-2)
        int index = targetChoice - 1;

        // Validation Check: Make sure the user chose a valid target array slot
        if (index >= 0 && index < arenaHorde.size()) {
            if (arenaHorde[index].health > 0) {
                std::cout << "\n[COMBAT] You slash the " << arenaHorde[index].name << " for 30 damage!" << std::endl;
                arenaHorde[index].health -= 30;

                // Retaliation: If the hit monster survived, it hits back using its custom damage attribute!
                if (arenaHorde[index].health > 0) {
                    std::cout << "[COMBAT] The " << arenaHorde[index].name << " retaliates for " 
                              << arenaHorde[index].damage << " damage!" << std::endl;
                    playerHealth -= arenaHorde[index].damage;
                } else {
                    std::cout << "[COMBAT] " << arenaHorde[index].name << " collapses into dust!" << std::endl;
                }
            } else {
                std::cout << "\n[COMBAT] You slice a corpse! The " << arenaHorde[index].name << " is already dead." << std::endl;
            }
        } else {
            std::cout << "\n[ERROR] Invalid targeting coordinate. You miss your swing completely!" << std::endl;
        }
    }

    std::cout << "\n======================================" << std::endl;
    if (playerHealth <= 0) {
        std::cout << "💀 playerHealth depleted. GAME OVER. 💀" << std::endl;
    } else {
        std::cout << "👋 Simulation ended safely. Portfolio assets secure. 👋" << std::endl;
    }

    return 0;
}
