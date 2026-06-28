// Monster.h
#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>

// The Blueprint definition
struct Monster {
    std::string name;
    int health;
    int damage;
    char symbol;
};

// Declaring our function interface so main.cpp knows it exists
void printStatusReport(int playerHp, const std::vector<Monster>& horde);

#endif
