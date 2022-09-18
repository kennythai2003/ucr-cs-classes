#include <iostream>
using namespace std;

#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackStrength, int rank)
    :Character(WIZARD, name, health, attackStrength), rank(rank)
{}

void Wizard::attack(Character &enemy){
    if (enemy.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(enemy);

        double attack;
        attack = attackStrength * (this->rank * (1.0 / opp.rank));
        opp.damage(attack);
        cout << "Wizard " << this->name << " attacks " << opp.name << " --- POOF!!" << endl;
        cout << opp.name << " takes " <<attack << " damage." << endl;
    }
    else {
        enemy.damage(this->attackStrength);
        cout << "Wizard " << this->name << " attacks " << enemy.getName() << " --- POOF!!" << endl;
        cout << enemy.getName() << " takes " << this->attackStrength << " damage." << endl;
    }
}