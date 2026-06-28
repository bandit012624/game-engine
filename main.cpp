#include <iostream>

int main() {
    // 1. Creating (Declaring) our storage boxes
    int playerHealth = 100;
    float playerX = 12.5f; // The 'f' tells C++ this is a float number
    char playerIcon = 'P';
    bool isAlive = true;

    // 2. Outputting the data from memory to the screen
    std::cout << "--- ENGINE RAM REPORT ---" << std::endl;
    std::cout << "Player Health: " << playerHealth << std::endl;
    std::cout << "Player Location X: " << playerX << std::endl;
    std::cout << "Player Visual Icon: " << playerIcon << std::endl;
    std::cout << "Is Player Alive? (1=True, 0=False): " << isAlive << std::endl;

    return 0;
}
