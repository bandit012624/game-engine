// Monster.h
#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>

struct Monster {
    std::string name;
    int health;
    int damage;
    char symbol;
};

void printStatusReport(int playerHp, const std::vector<Monster>& horde, const Monster* target);

#endif
