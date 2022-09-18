#ifndef _WARRIOR_H__
#define _WARRIOR_H__

using namespace std;
#include <iostream>
#include "Character.h"

class Warrior: public Character{
 private:
    string allegiance;

 public:
    Warrior(const string &, double, double, string);
    void attack(Character &);   
};

#endif