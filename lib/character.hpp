// include standard lib
#include <string>

#include "types.hpp"
#include "equipment.hpp"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

using namespace std;

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

class Character {

public:
    string characterName;
    string playerName;
    ClassType classType{ClassType::BARBARIAN};
    int level{1};
    Race race{Race::HUMAN};
    Alignment alignment{Alignment::NEUTRAL};
    int xp{0};
    int armorClass;
    int initiative;
    int speed;
    int maxHitPoints;
    int currentHitPoints;
    int tempHitPoints;


    int inspiration;
    int proficiencyBonus;
    int passivePerception;

    Abilities abilities;
    vector<Equipment*> inventory;
    vector<Weapon*> equippedWeapons;
    vector<Armor*> equippedArmor;
    Coin purse;

    Character();
    Character(string charName, 
        string playerName, 
        ClassType classType, 
        Race race, 
        Alignment alignment);

    ~Character();

    
    // Method to equip a weapon
    void equipWeapon(Weapon* weapon);
    // Un-equip a weapon
    void unequipWeapon(Weapon* weapon);
    // Method to equip armor
    void equipArmor(Armor* armor);
    // Unequip armor
    void unequipArmor(Armor* armor);
    // Method to add to inventory
    void addToInventory(Equipment* item);
    // Method to remove from inventory
    void removeFromInventory(Equipment* item);
private:
    // Initialize using standard array values
    void initializeAbilities();

};
#endif // CHARACTER_HPP