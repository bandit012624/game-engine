#include <iostream>

int main() {
    int playerHealth = 100;
    int roundCounter = 1;

    std::cout << "===ARENA SIMULATOR INITIALING ===" << std::endl;

    // The loop keeps running as long as playerhealth is greater than 0
    while (playerHealth > 0) {
        std::cout << "\n---ROUND " << roundCounter << " ---" << std::endl;
        std::cout << "Player Health: " << playerHealth << std::endl;

        // Simulation: Enemy strikes for 25 damage each round
        std::cout << "[COMBAT] Enemy slashes player for 25 damage!" << std::endl;
        playerHealth -= 25;

        // Increment our round counter by 1 so we track time
        roundCounter += 1;
    }
    
    // Once playerHealth hits 0 or less, the loop breaks and code continues here:
    std::cout << "\n==================================" << std::endl;
    std::cout << "💀 playerHealth hit " << playerHealth << "! LOOP BROKEN. GAME OVER. 💀" << std::endl;
    
    return 0;
    }

