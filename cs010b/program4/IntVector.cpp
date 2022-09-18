#include<iostream>
#include<stdexcept>

using namespace std;

#include "IntVector.h"

void IntVector::expand(){
    //lecture notes: create a new array, double capacity, and copy over elements from old array
    // delete old array to avoid memory heap, 
    int *currVector = _data;
    if (_capacity == 0) {
        _capacity = 1;
        _data = new int [_capacity];
    } 
    else {
        _capacity = _capacity * 2;
        _data = new int [_capacity];
        for (unsigned int i = 0; i < _size; ++i) {
            _data[i] = currVector[i];
        }
        delete[] currVector;
    }
}
void IntVector::expand(unsigned amount) {
    //same as other expand but capcity is increased by amount instead of doubled
    int *currVector = _data;
    _capacity = _capacity + amount;
    _data = new int [_capacity];
    for (unsigned int i = 0; i < _size; ++i) {
        _data[i] = currVector[i];
    }
    delete[] currVector;
}

IntVector::IntVector(unsigned capacity, int value) {
    // set both the size and capacity of the IntVector to the 
    // value of the parameter passed in
    // CHECK WITH TA BEFORE LEAVING LAB
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
    //cout << "destroyed" << endl; used to test destructor

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

int & IntVector::at(unsigned index) {
    //same as above at function
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

int & IntVector::front (){
    //same as above front fuciton
    return _data[0];   
}

const int & IntVector::back() const{
    return _data[_size - 1];
}

int & IntVector::back () {
    //same as above back function
    return _data[_size - 1];
}


void IntVector::insert(unsigned index, int value){
    //acount of size >capacity
    if (_size >= _capacity) {
        expand();
        _size = _size + 1;
    } else {
        _size = _size + 1;
    }

    if (index >= _size) {
        throw std::out_of_range("IntVector::insert_range_check");
    }
    else {
        //shift all elemets to the righ
        for (unsigned int i = index + 1; i < _size; ++i) {
            _data[i] = _data[i - 1]; 
        }
    }
    _data[index] = value;
}

void IntVector::erase(unsigned index){
    //removes the value at position index and shifts all of the values 
    //at positions greater than index to the left by one
    if (index >= _size) {
        throw std::out_of_range("IntVector::erase_range_check");
    }
    else {
        for (unsigned int i = index; i < _size - 1; ++i) {
            _data[i] = _data[i + 1];
        }
    }
    _size = _size - 1;
}

void IntVector::assign(unsigned n, int value) {
    //acount for size > capacity
    if (_capacity < n){
        if (_capacity < n - _capacity) {
            expand (n - _capacity);
        }
        else{
            expand();
        }
    }
    _size = n;

    for (unsigned int i = 0; i < _size; ++i) {
        _data[i] = value;
    }
}

void IntVector::push_back(int value) {
    //acount for size > capacity
    if (_size >= _capacity) {
        expand();
        _size = _size + 1;
    } else {
        _size = _size + 1;
    }
    
    _data[_size - 1] = value; 
}

void IntVector::pop_back() {
    //decrease size by 1
    _size = _size - 1;
}


void IntVector::clear(){
    //set size to 0
    _size = 0;
}

void IntVector::resize(unsigned size, int value){

    //account for size > capacity
    if (_capacity < size){
        if (_capacity < size - _capacity) {
            expand (size - _capacity);
        }
        else{
            expand();
        }
    }

    //update vector and size
    if (size < _size) {
        _size = size;
    }
    else {
        for (unsigned int i = _size; i < size; ++i) {
            _data[i] = value; 
        }
        _size = size;
    }
}

void IntVector::reserve(unsigned n) {
    // sets minimum capcity if n is greater than current capacity
    if (n > _capacity) {
        _capacity = n;
    }
}
