#include <iostream>

int main() {
    int playerHealth = 100;

    std::cout << "--- ENEMY ENGAGEMENT ---" << std::endl;
    std::cout << "Starting Player Health: " << playerHealth << std::endl;

    // 1. SIMULATION: A massive boss monster hits the player for 120 damage!
    std::cout << "\n[COMBAT] Boss uses Flame Breath! You take 120 damage!" << std::endl;
    playerHealth -= 120; 

    std::cout << "Current Player Health: " << playerHealth << std::endl;

    // 2. THE ENGINE DECISION TREE
    // '<=' means 'less than or equal to'
    if (playerHealth <= 0) {
        std::cout << "\n[ENGINE] WARNING: Player health depleted!" << std::endl;
        std::cout << "💀 GAME OVER: Your character has perished. 💀" << std::endl;
    } 
    else {
        std::cout << "\n[ENGINE] STATUS: Player survived the attack!" << std::endl;
        std::cout << "🛡️ Keep fighting! 🛡️" << std::endl;
    }

    return 0;
}
