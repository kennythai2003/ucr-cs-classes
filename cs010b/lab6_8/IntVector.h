#ifndef INTVECTOR_H
#define INTVECTOR_H

using namespace std;

class IntVector {
 private:
    unsigned _size; //stores the size of the IntVector (the number of elements currently being used to store the user's values)
    unsigned _capacity; //store the size of the array (therefore must always be >= to _size)
    int *_data; //a pointer that stores the address of the dynamically-allocated array of integers
 public:
    IntVector(unsigned capacity = 0, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int & at(unsigned index) const;
    const int & front() const;
    const int & back() const;
};

#endif