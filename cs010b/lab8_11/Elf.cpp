#include <iostream>
using namespace std;

#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrength, string family)
    :Character(ELF, name, health, attackStrength), family(family)
{}

void Elf::attack(Character &enemy) {
    if (enemy.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(enemy);

        if (opp.family == this->family) {
            cout << "Elf " << this->name << " does not attack Elf " << opp.name << '.' << endl;
            cout << "They are both members of the " << this->family << " family." << endl;
        }
        else {
            double attack;
            attack = attackStrength * (this->health / MAX_HEALTH);
            opp.damage(attack);
            cout << "Elf " << this->name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
            cout << opp.getName() << " takes " << attack << " damage." << endl;
        }
    }

    else {
        double attack;
        attack = attackStrength * (health / MAX_HEALTH);
        enemy.damage(attack);
        cout << "Elf " << this->name << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
        cout << enemy.getName() << " takes " << attack << " damage." << endl;
    }

}