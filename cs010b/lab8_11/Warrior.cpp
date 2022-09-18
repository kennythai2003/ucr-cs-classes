#include <iostream>
using namespace std;

#include "Warrior.h"

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance)
    :Character(WARRIOR, name, health, attackStrength), allegiance(allegiance)
{}

void Warrior::attack(Character &enemy){
    if(enemy.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior &>(enemy);

        if(opp.allegiance == this->allegiance){
            cout << "Warrior " << this->name << " does not attack Warrior " << opp.getName() << '.' << endl;
            cout << "They share an allegiance with " << this->allegiance << '.' << endl;
        }
        else{
            double attack;
            attack = (this->health / MAX_HEALTH) * attackStrength;
            opp.damage(attack);
            cout << "Warrior " << name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
            cout << opp.getName() << " takes " << attack << " damage." << endl;
        }
    }
    else{
        double attack;
        attack = (health / MAX_HEALTH) * attackStrength;
        enemy.damage(attack);
        cout << "Warrior " << this->name << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
        cout << enemy.getName() << " takes " << attack << " damage." << endl;
    }
}