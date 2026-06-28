#include <iostream>

int main() {
    int playerHealth = 100;
    char userChoice = ' '; // Storing your keyboard input choice

    std::cout << "=== INTERACTIVE GAME ENGINE BOOTED ===" << std::endl;
    std::cout << "Instructions: Type 'a' to Attack, 'd' to Defend, or 'q' to Quit." << std::endl;

    // The game loop keeps running as long as you are alive AND you haven't typed 'q'
    while (playerHealth > 0 && userChoice != 'q') {
        std::cout << "\n--------------------------------------" << std::endl;
        std::cout << "Current Player Health: " << playerHealth << std::endl;
        std::cout << "Enter Action (a/d/q): ";
        
        // Pause the engine and wait for the user to type a key and press Enter
        std::cin >> userChoice;

        // Process your decision tree
        if (userChoice == 'a') {
            std::cout << "[COMBAT] You charge forward! Enemy counter-attacks you for 20 damage!" << std::endl;
            playerHealth -= 20;
        } 
        else if (userChoice == 'd') {
            std::cout << "[COMBAT] You raise your shield! Enemy attack is blocked safely." << std::endl;
        } 
        else if (userChoice == 'q') {
            std::cout << "[ENGINE] Shutdown command received." << std::endl;
        } 
        else {
            std::cout << "[ERROR] Invalid input code. Enemy strikes you for 5 damage while you fumble!" << std::endl;
            playerHealth -= 5;
        }
    }

    // Post-Loop Cleanup Check
    std::cout << "\n======================================" << std::endl;
    if (playerHealth <= 0) {
        std::cout << "💀 playerHealth depleted. GAME OVER. 💀" << std::endl;
    } else {
        std::cout << "👋 Engine safely exited. Thank you for playing! 👋" << std::endl;
    }

    return 0;
}
