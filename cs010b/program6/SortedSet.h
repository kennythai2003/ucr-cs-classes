#ifndef _SORTEDSSET_H__
#define _SORTEDSSET_H__

#include <iostream>

#include "IntList.h"
using namespace std;

class SortedSet : public IntList{

public: 

    //constructirs and destroyers
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);
    ~SortedSet();

    //accessors
    bool in(int value);
    SortedSet operator|(const SortedSet &rhs);
    SortedSet operator&(const SortedSet &rhs);

    //mutators
    void add(int value);
    void push_front(int value);
    void push_back(int value);
    void insert_ordered(int value);
    SortedSet operator|=(const SortedSet &rhs);
    SortedSet operator&=(const SortedSet &rhs);

};

#endif