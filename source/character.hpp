// include standard lib
#include <string>

#include "types.hpp"
#include "equipment.hpp"

using namespace std;

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
    SavingThrows savingThrows;
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

    // Add to purse
    Coin& addCoin(const Coin& amount);
    // Remove from purse
    Coin& spendCoin(const Coin& amount);
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