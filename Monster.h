// Monster.h
#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>

// 1. Define an Enumeration for Item Types
enum ItemType {
    NONE,
    HEALTH_POTION,
    IRON_SWORD
};

// 2. Add the dropItem attribute to the Monster blueprint
struct Monster {
    std::string name;
    int health;
    int damage;
    char symbol;
    ItemType dropItem; // What item does this specific monster carry?
};

void printStatusReport(int playerHp, const std::vector<Monster>& horde, const Monster* target, const std::vector<std::string>& inventory);

#endif
