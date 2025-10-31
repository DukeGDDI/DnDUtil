#include <string>

using namespace std;

class Coin {
public: 
    int copper;
    int silver;
    int gold;
    int platinum;

    Coin() : copper(0), silver(0), gold(0), platinum(0) {}
    Coin(int copper = 0, int silver = 0, int gold = 0, int platinum = 0) :
        copper(copper), silver(silver), gold(gold), platinum(platinum) {}

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
};

// Abstract base class for all equipment
class Equipment {
public:
    string name;
    int weight;
    Coin cost;

    Equipment(string name, int weight, Coin cost) :
        name(name), weight(weight), cost(cost) {}
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

class Weapon : public Equipment {
public:
    int damage;
    DamageType damageType;

    Weapon(string name, int weight, int value, int damage, DamageType damageType) :
        Equipment(name, "Weapon", weight, value), damage(damage), damageType(damageType) {}
};

class Armor : public Equipment {
public: 
    int armorClassBonus;
    bool stealthDisadvantage;

    Armor(string name, int weight, int value, int armorClassBonus, bool stealthDisadvantage) :
        Equipment(name, "Armor", weight, value), armorClassBonus(armorClassBonus), stealthDisadvantage(stealthDisadvantage) {}  

};