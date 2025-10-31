
#include "types.hpp"
#include <ostream>

/// Overload the << operator for ClassType
std::ostream& operator<<(std::ostream& os, ClassType type) {
    switch (type) {
        case ClassType::BARBARIAN: os << "Barbarian"; break;
        case ClassType::BARD:      os << "Bard"; break;
        case ClassType::CLERIC:    os << "Cleric"; break;
        case ClassType::DRUID:     os << "Druid"; break;
        case ClassType::FIGHTER:   os << "Fighter"; break;
        case ClassType::MONK:      os << "Monk"; break;
        case ClassType::PALADIN:   os << "Paladin"; break;
        case ClassType::RANGER:    os << "Ranger"; break;
        case ClassType::ROGUE:     os << "Rogue"; break;
        case ClassType::SORCERER:  os << "Sorcerer"; break;
        case ClassType::WARLOCK:   os << "Warlock"; break;
        case ClassType::WIZARD:    os << "Wizard"; break;
        default:                   os << "Unknown"; break;
    }
    return os;
}

// Overload the << operator for Race
std::ostream& operator<<(std::ostream& os, Race race) {
    switch (race) {
        case HUMAN:       os << "Human"; break;
        case ELF:         os << "Elf"; break;
        case DWARF:       os << "Dwarf"; break;
        case HALFLING:    os << "Halfling"; break;
        case ORC:         os << "Orc"; break;
        case GNOME:       os << "Gnome"; break;
        case TIEFLING:    os << "Tiefling"; break;
        case DRAGONBORN:  os << "Dragonborn"; break;
        case GOLIATH:     os << "Goliath"; break;
        default:          os << "Unknown"; break;
    }
    return os;
}

// Overload the << operator for DamageType
std::ostream& operator<<(std::ostream& os, DamageType type) {
    switch (type) {
        case SLASHING:     os << "Slashing"; break;
        case PIERCING:     os << "Piercing"; break;
        case BLUDGEONING:  os << "Bludgeoning"; break;
        case FIRE:         os << "Fire"; break;
        case COLD:         os << "Cold"; break;
        case LIGHTNING:    os << "Lightning"; break;
        case ACID:         os << "Acid"; break;
        case POISON:       os << "Poison"; break;
        case NECROTIC:     os << "Necrotic"; break;
        case RADIANT:      os << "Radiant"; break;
        case THUNDER:      os << "Thunder"; break;
        case FORCE:        os << "Force"; break;
        case PSYCHIC:      os << "Psychic"; break;
        default:           os << "Unknown"; break;
    }
    return os;
}

// Overload the << operator for ArmorType
std::ostream& operator<<(std::ostream& os, ArmorType type) {
    switch (type) {
        case UNARMORED:    os << "Unarmored"; break;
        case LIGHT:        os << "Light"; break;
        case MEDIUM:       os << "Medium"; break;
        case HEAVY:        os << "Heavy"; break;
        case SHIELD:       os << "Shield"; break;
        default:           os << "Unknown"; break;
    }
    return os;
}

