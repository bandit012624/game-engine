// Skills.h
#ifndef SKILLS_H
#define SKILLS_H

#include <iostream>
#include <string>

// Struct tracking player secondary resource pools
struct SkillBook {
    int mana = 50;
    int maxMana = 50;
    std::string spellName = "Fireball";
    int spellCost = 20;
    int baseSpellDamage = 45;
};

// Quick helper to display active magic pool state metrics
inline void printManaBar(const SkillBook& book) {
    std::cout << "🔮 MANA POOL: " << book.mana << "/" << book.maxMana << " MP" << std::endl;
}

#endif
