#include <iostream>
#include <stdexcept>
#include "IntVector.h"
using namespace std;

int main() {
    IntVector v1 (4, 4);

    cout << "output size: " << v1.size() << endl; 
    cout << "output capacity: " << v1.capacity() << endl;
    cout << "output elements: ";
    for( unsigned int i = 0; i < 4; ++i) {
        cout << v1.at(i) << " ";
    }
    // out of range has been checked with 10, the above loop is used for reg testing
    cout << endl;
    cout << "output front: " << v1.front() << endl;
    cout << "output back:"  << v1.back() << endl;

}