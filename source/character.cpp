// include standard lib
#include <string>

#include "character.hpp"

using namespace std;

Character::Character() : characterName("Unnamed"), 
    playerName("Unknown"), 
    classType(ClassType::BARBARIAN),
    level(1),
    race(Race::HUMAN),
    alignment(Alignment::NEUTRAL),
    xp(0),
    armorClass(10),
    initiative(0),
    speed(30),
    maxHitPoints(10),
    currentHitPoints(10),
    tempHitPoints(0),
    inspiration(0),
    proficiencyBonus(2),
    passivePerception(10) {
        initializeAbilities();

}

Character::Character(string charName, 
    string playerName, 
    ClassType classType, 
    Race race, 
    Alignment alignment) : characterName(charName), 
    playerName(playerName), 
    classType(classType), 
    race(race), 
    alignment(alignment) {

    initializeAbilities();
}

void Character::initializeAbilities() {
    switch(classType) {
        case ClassType::BARBARIAN:
            abilities.strength = 15;
            abilities.dexterity = 13;
            abilities.constitution = 14;
            abilities.intelligence = 10;
            abilities.wisdom = 12;
            abilities.charisma = 8;
            break;
        case ClassType::BARD:
            abilities.strength = 8;
            abilities.dexterity = 14;
            abilities.constitution = 12;
            abilities.intelligence = 13;
            abilities.wisdom = 10;
            abilities.charisma = 15;
            break;
        // Additional class types can be added here
        default:
            abilities.strength = 10;
            abilities.dexterity = 10;
            abilities.constitution = 10;
            abilities.intelligence = 10;
            abilities.wisdom = 10;
            abilities.charisma = 10;
            break;
    }
}