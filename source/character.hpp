// include standard lib
#include <string>

using namespace std;
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

enum Race {
    HUMAN,
    ELF,
    DWARF
};

enum Alignment {
    GOOD,
    NEUTRAL,
    EVIL
};

struct Abilities {
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
};

struct SavingThrows {
    bool strength;
    bool dexterity;
    bool constitution;
    bool intelligence;
    bool wisdom;
    bool charisma;
};

class Armor {
public:
    string name;
    int armorClassBonus;
    bool stealthDisadvantage;
};

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

    Character();
    Character(string charName, 
        string playerName, 
        ClassType classType, 
        Race race, 
        Alignment alignment);


private:
    // Initialize using standard array values
    void initializeAbilities();

};