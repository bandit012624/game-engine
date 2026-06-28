#include <iostream>

// 1. CREATING OUR FIRST FUNCTION
// This function takes our player's health as an input parameter and displays a clean banner
void printStatusReport(int health) {
    std::cout << "\n--------------------------------------" << std::endl;
    std::cout << "💖 ENGINE HP MONITOR: " << health << " HP" << std::endl;
    
    // The function can even run its own internal decision logic!
    if (health < 40) {
        std::cout << "⚠️ WARNING: Player health is dangerously low! ⚠️" << std::endl;
    }
    
    std::cout << "Enter Action (a = Attack, d = Defend, q = Quit): ";
}

// 2. THE CENTRAL ENGINE HUB
int main() {
    int playerHealth = 100;
    char userChoice = ' ';

    std::cout << "=== MODULAR GAME ENGINE BOOTED ===" << std::endl;

    while (playerHealth > 0 && userChoice != 'q') {
        
        // CALLING OUR CUSTOM FUNCTION HERE
        // We pass 'playerHealth' into the function so it knows what number to print
        printStatusReport(playerHealth);
        
        std::cin >> userChoice;

        if (userChoice == 'a') {
            std::cout << "[COMBAT] You slash! Enemy counter-attacks for 25 damage!" << std::endl;
            playerHealth -= 25;
        } 
        else if (userChoice == 'd') {
            std::cout << "[COMBAT] Shield raised! Safe from harm." << std::endl;
        } 
        else if (userChoice == 'q') {
            std::cout << "[ENGINE] Exit flag captured." << std::endl;
        } 
        else {
            std::cout << "[ERROR] Wrong key! Mistake costs you 5 health." << std::endl;
            playerHealth -= 5;
        }
    }

    std::cout << "\n======================================" << std::endl;
    if (playerHealth <= 0) {
        std::cout << "💀 playerHealth depleted. GAME OVER. 💀" << std::endl;
    } else {
        std::cout << "👋 Engine safely shut down. Goodbye! 👋" << std::endl;
    }

    return 0;
}
