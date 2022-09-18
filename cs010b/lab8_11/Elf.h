#ifndef __ELF_H_
#define __ELF_H_

using namespace std;
#include <iostream>
#include "Character.h"

class Elf: public Character { 
 private:
    string family;

 public:
    Elf(const string &, double, double, string);
    void attack(Character &);
};

#endif