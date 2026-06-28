// Monster.h
#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>
#include "Skills.h" // Import our new skill structures

enum ItemType {
    NONE,
    HEALTH_POTION,
    IRON_SWORD
};

struct Monster {
    std::string name;
    int health;
    int damage;
    char symbol;
    ItemType dropItem;
};

void printStatusReport(int playerHp, const SkillBook& magic, const std::vector<Monster>& horde, const Monster* target, const std::vector<std::string>& inventory);

#endif
