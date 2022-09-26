#include <iostream>
#include "IntList.h"
using namespace std;

int main(){
    //test for normal list
    IntList test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);
    test.pop_front();
    test.pop_back();
    cout << test << endl; //expecting 2-5
    test.printReverse(); //expecting 5-2

    //test for empty
    IntList test1;
    cout << test1.empty() << endl;

    //test for single node
    IntList test2;
    test2.push_back(1);
    cout << test2 << endl;
    test2.pop_front();
    test2.push_back(2);
    cout << test2 << endl;
    test2.pop_back();
    test2.push_back(3);
    cout << test2 << endl;
    return 0;
}