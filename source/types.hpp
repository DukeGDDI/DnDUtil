#include <iostream>
#include <string>

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


struct Abilities {
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
};

// Overload the << operator for Abilities
std::ostream& operator<<(std::ostream& os, const Abilities& abilities);

struct SavingThrows {
    bool strength;
    bool dexterity;
    bool constitution;
    bool intelligence;
    bool wisdom;
    bool charisma;
};

// Overload the << operator for SavingThrows
std::ostream& operator<<(std::ostream& os, const SavingThrows& savingThrows);