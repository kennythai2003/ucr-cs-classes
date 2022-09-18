#include <iostream>
#include <stdexcept>

using namespace std;

#include "IntVector.h"

int main() {
    
    // testing: IntVector(unsigned capacity = 0, int value = 0);
    IntVector v1 (4, 4);

    // testing: ~IntVector();
    IntVector destroy (2, 2);
    destroy.~IntVector();
    // cout << destroy.front();

    // testing: unsigned size() const;
    cout << "output size: " << v1.size() << endl; 

    // testing: unsigned capacity() const;
    cout << "output capacity: " << v1.capacity() << endl;

    // testing: bool empty() const;
    if (!v1.empty()) {
        cout << "completed empty test" << endl;
    }

    // testing: const int & at(unsigned index) const and int & at(unsigned index);
    cout << "testing at functions: ";
    for( unsigned int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    // testing: const int & front() const and int & front ();
    cout << "output front: " << v1.front() << endl;

    // testing: const int & back() const and  int & back ();
    cout << "output back:"  << v1.back() << endl;

    // testing: void insert(unsigned index, int value);
    v1.insert(0, 3);
    cout << "test for insert: " << v1.at(0) << endl;

    // testing: void erase(unsigned index);
    v1.erase(0);
    cout << "test for erase: " << v1.at(0) << endl;

    // testing: void assign(unsigned n, int value);
    v1.assign(10, 10);
    cout << "test for assign: ";
    for( unsigned int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    // testing: void push_back(int value);
    v1.push_back(11);
    cout << "testing for push_back: " << v1.back() << endl;
    
    // testing: void pop_back();
    v1.pop_back();
    cout << "testing for pp_back: " << v1.back() << endl;
   
    // testing: void clear();
    IntVector v2 (20, 20);
    v2.clear();
    cout << "testing for clear: " << v1.size() << endl;

    // testing: void resize(unsigned size, int value = 0);
    v1.resize(3, 4);
    cout << "test for resize: ";
    for( unsigned int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << " ";
    }
    cout << endl;   

    // testing: void reserve(unsigned n);
    v1.reserve(90);
    cout << "test for reserve " << v1.size() << endl;
    return 0;
}