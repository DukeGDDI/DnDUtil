#include <string>
#include <vector>
#include "util.hpp"
#include "types.hpp"
#include "coin.hpp"

using namespace std;

// Abstract base class for all equipment
class Equipment {
public:
    string id;
    string name;
    int weight;
    Coin cost;

    Equipment(string name, int weight, Coin cost) :
        name(name), weight(weight), cost(cost) {
            id = get_uuid();
        }
};

class Purse : public Equipment {
public:
    Coin coins;

    Purse() : Equipment("Purse", 0, Coin()), coins() {}

    Purse(Coin amount) : Equipment("Purse", 0, amount), coins(amount) {}

    // Add to purse - return updated purse
    Coin& addCoin(const Coin& amount);
    // Remove from purse - return updated purse
    Coin& spendCoin(const Coin& amount);

    bool hasSufficientFunds(const Coin& amount) const;
    // compute total weight of coins
    int totalWeight() const;
    // compute total value of coins in copper
    int totalValueInCopper() const;
};



// Weapon class derived from Equipment
class Weapon : public Equipment {
public:
    int damage;
    DamageType damageType;

    Weapon() : Equipment("Sword", 0, Coin()), damage(0), damageType(SLASHING) {}
    Weapon(string name, int weight, Coin value, int damage, DamageType damageType) :
        Equipment(name, weight, value), damage(damage), damageType(damageType) {}
};



class Armor : public Equipment {
public: 
    int armorClassBonus;
    ArmorType armorType;
    bool stealthDisadvantage;

    Armor() : Equipment("Soft Clothing", 0, Coin()), armorClassBonus(0), armorType(UNARMORED), stealthDisadvantage(false) {}
    Armor(string name, int weight, Coin value, int armorClassBonus, ArmorType armorType, bool stealthDisadvantage) :
        Equipment(name, weight, value), armorClassBonus(armorClassBonus), armorType(armorType), stealthDisadvantage(stealthDisadvantage) {}

};

class Tool : public Equipment {
public:
    Tool(string name, int weight, Coin value) :
        Equipment(name, weight, value) {}

    virtual void useTool() = 0; // Pure virtual function making this an abstract class
};

class WeaponFactory {
public:
    static Weapon registerWeapon(string name, int weight, Coin value, int damage, DamageType damageType) {
        return Weapon(name, weight, value, damage, damageType);
    }

    static vector<Weapon> getAllWeapons();
};