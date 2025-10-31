#include "util.hpp"
#include "equipment.hpp"
#include <ostream>

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

// Overload the << operator for Coin
std::ostream& operator<<(std::ostream& os, const Coin& coin) {
    os << coin.platinum << " pp, "
       << coin.gold << " gp, "
       << coin.silver << " sp, "
       << coin.copper << " cp";
    return os;
}