#include<iostream>
#include<stdexcept>
using namespace std;

#include "IntVector.h"

IntVector::IntVector(unsigned capacity, int value) {
    // set both the size and capacity of the IntVector to the 
    // value of the parameter passed in
    _capacity = capacity;
    _size = capacity;
    if (_capacity == 0) {
        _data = nullptr;
    } 
    else {
        _data = new int[_capacity]; 
        //initalize all elements of array ot value of the 2nd parameter
        for (unsigned int i = 0; i < _capacity; ++i) {
            _data[i] = value;
        }
    }
}
IntVector::~IntVector(){ 
    //destory the array pointed to by the int pointer named _data.
    delete[] _data;
}

unsigned IntVector::size() const{
    //returns the current size (not the capacity) of the IntVector object, 
    //which is the values stored in the _size member variable
    return _size;
}

unsigned IntVector::capacity() const{
    //returns the current capacity (not the size) of the IntVector object, 
    //which is the value stored in the _capacity member variable
    return _capacity;
}

bool IntVector::empty() const{
    bool empty;
    if (_size == 0) {
        empty = true;
    }
    else {
        empty = false;
    }
    return empty;
}

const int & IntVector::at(unsigned index) const{
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}

const int & IntVector::front() const{
    return _data[0];
}

const int & IntVector::back() const{
    return _data[_size - 1];
}