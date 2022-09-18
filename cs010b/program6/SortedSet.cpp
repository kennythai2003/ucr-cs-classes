//constructirs and destroyers
#include <iostream>
using namespace std;
#include "IntList.h"
#include "SortedSet.h"

SortedSet::SortedSet() 
    :IntList()
{}

SortedSet::SortedSet(const SortedSet &list)
    :IntList(list)
{}

SortedSet::SortedSet(const IntList &list) 
    :IntList(list) {
        IntList::selection_sort();
        IntList::remove_duplicates();    
    }

SortedSet::~SortedSet(){}


//accessors
bool SortedSet::in(int value) {
    bool inList = false;
    for (IntNode *i = head; i != nullptr; i = i-> next) {
        if (i->value == value) {
            inList = true;
            }
    }
    return inList;
}

SortedSet SortedSet::operator|(const SortedSet &rhs) {
    SortedSet s1= rhs;
    for (IntNode *i = this->head; i != nullptr; i = i-> next) {
        s1.add(i->value);
    }
    return s1;
}

SortedSet SortedSet::operator&(const SortedSet &rhs) {
    SortedSet s1;
    SortedSet cpy = rhs;
    for (IntNode *i = this->head; i != nullptr; i = i-> next) {
        if(cpy.in(i->value)) {
            s1.add(i->value);
        }
    }
    return s1;
}

//mutators
void SortedSet::add(int value) {
    if (!in(value)) {
        insert_ordered(value);
    }
}

void SortedSet::push_front(int value){
    insert_ordered(value);
}

void SortedSet::push_back(int value){
    insert_ordered(value);
}

void SortedSet::insert_ordered(int value){
    if (!in(value)) {
        IntList::insert_ordered(value);
    }
}

SortedSet SortedSet::operator|=(const SortedSet &rhs){ 
    // SortedSet s1= rhs;
    // for (IntNode *i = this->head; i != nullptr; i = i-> next) {
    //     s1.add(i->value);
    // }
    *this = *this|rhs;
    return *this;
}

SortedSet SortedSet::operator&=(const SortedSet &rhs){
    *this = *this&rhs;
    return *this;
}
