#ifndef _WIZARD_H_
#define _WIZARD_H_

using namespace std;
#include <iostream>
#include "Character.h"

class Wizard: public Character{
 private:
    int rank;

 public:
    Wizard(const string &, double, double, int);
    void attack(Character &);
};

#endif