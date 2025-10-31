#include <string>
#include <vector>
#include "util.hpp"

using namespace std;

class Coin {
public: 
    int copper;
    int silver;
    int gold;
    int platinum;

    Coin() : copper(0), silver(0), gold(0), platinum(0) {}
    Coin(int copper, int silver, int gold, int platinum) :
        copper(copper), silver(silver), gold(gold), platinum(platinum) {}

    ~Coin() = default;

    // Overload the + operator to add two Coin objects
    Coin operator+(const Coin& other);
    // Overload the - operator to subtract two Coin objects
    Coin operator-(const Coin& other);
    // Overload the += operator to add and assign two Coin objects
    Coin& operator+=(const Coin& other);
    // Overload the -= operator to subtract and assign two Coin objects
    Coin& operator-=(const Coin& other);
    // Overload the == operator to compare two Coin objects
    bool operator==(const Coin& other);
    // Overload the != operator to compare two Coin objects
    bool operator!=(const Coin& other);
    // Overload the < operator to compare two Coin objects
    bool operator<(const Coin& other);
    // Overload the <= operator to compare two Coin objects
    bool operator<=(const Coin& other);
    // Overload the >= operator to compare two Coin objects
    bool operator>=(const Coin& other);
    // Overload the > operator to compare two Coin objects
    bool operator>(const Coin& other);
    // Overload the << operator for easy printing of Coin objects
    friend ostream& operator<<(ostream& os, const Coin& coin);

private:
    // Helper function to convert all coins to copper for comparison
    int totalCopper() const {
        return copper + silver * 10 + gold * 100 + platinum * 1000;
    }
};

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

// Weapon class derived from Equipment
class Weapon : public Equipment {
public:
    int damage;
    DamageType damageType;

    Weapon() : Equipment("Sword", 0, Coin()), damage(0), damageType(SLASHING) {}
    Weapon(string name, int weight, Coin value, int damage, DamageType damageType) :
        Equipment(name, weight, value), damage(damage), damageType(damageType) {}
};

enum ArmorType {
    UNARMORED,
    LIGHT,
    MEDIUM,
    HEAVY,
    SHIELD
};

std::ostream& operator<<(std::ostream& os, ArmorType type);

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