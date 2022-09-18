#include <iostream>
using namespace std;

#include "Character.h"

Character::Character(HeroType type, const string &name, double health, double attackStrength)  
    :type(type), name(name), health(health), attackStrength(attackStrength)
{}

HeroType Character::getType() const{
    return type;
}   

const string & Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

void Character::damage(double d) {
    health = health - d;
}

bool Character::isAlive() const {
    bool alive = false;
    if (health > 0) {
        alive = true;
    }
    return alive;
}