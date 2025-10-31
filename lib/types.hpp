#include <iostream>
#include <string>

#ifndef TYPES_HPP
#define TYPES_HPP
enum class ClassType {
    BARBARIAN,
    BARD,
    CLERIC, 
    DRUID,
    FIGHTER,
    MONK,
    PALADIN,    
    RANGER,
    ROGUE,
    SORCERER,
    WARLOCK,
    WIZARD
};

// Overload the << operator for ClassType
std::ostream& operator<<(std::ostream& os, ClassType type);


enum Race {
    HUMAN,
    ELF,
    DWARF,
    HALFLING,
    ORC,
    GNOME,
    TIEFLING,
    DRAGONBORN,
    GOLIATH
};

// Overload the << operator for Race
std::ostream& operator<<(std::ostream& os, Race race);


enum Alignment {
    LAWFUL_GOOD,
    NEUTRAL_GOOD,
    CHAOTIC_GOOD,
    LAWFUL_NEUTRAL,
    NEUTRAL,
    CHAOTIC_NEUTRAL,
    LAWFUL_EVIL,
    NEUTRAL_EVIL,
    CHAOTIC_EVIL
};
// Overload the << operator for Alignment
std::ostream& operator<<(std::ostream& os, Alignment alignment);

enum DamageType {
    SLASHING,
    PIERCING,
    BLUDGEONING,
    FIRE,
    COLD,
    LIGHTNING,
    ACID,
    POISON,
    NECROTIC,
    RADIANT,
    THUNDER,
    FORCE,
    PSYCHIC
};

// Overload the << operator for DamageType
std::ostream& operator<<(std::ostream& os, DamageType type);

enum ArmorType {
    UNARMORED,
    LIGHT,
    MEDIUM,
    HEAVY,
    SHIELD
};

std::ostream& operator<<(std::ostream& os, ArmorType type);
#endif // TYPES_HPP