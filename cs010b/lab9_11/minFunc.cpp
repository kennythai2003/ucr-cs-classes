#include "minFunc.h"
// #include <iostream>
// using namespace std;

const int * min(const int arr[], int arrSize) {
    //minloc in main is a pointer
    //function returns a pointer/ location of minimum
    // it outputs the deference of the address of the minimum
    if (arrSize == 0) {
        return nullptr;
        //gives back an empty slot 
    }
    if (arrSize == 1) {
        // cout << "array at 1" << endl;
        return arr;
        //minimum is the only index
    }
    const int *minLocation = min(arr, arrSize - 1);
    // cout << "calling recursion function" << endl; 
    //updates if a new min is found^^

    //in every iteration
    // int index = arr[arrSize - 1];
    //used to check the last index be4 removing

    if (arr[arrSize - 1] < *minLocation) {
        //*minLocation is an address so we need to return the address so it could be later dereferenced
        // cout << "new min: " << index << endl;
        return &arr[arrSize - 1];
    }
    else {
        // cout << "no change in min: " << *minLocation << endl;
        return minLocation;
        //gives back old minimum
    }
}
