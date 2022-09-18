#include "IntList.h"
#include "SortedSet.h"

#include <iostream>
using namespace std;

int main() {
    SortedSet set1;
    set1.insert_ordered(8);
    set1.insert_ordered(4);
    set1.insert_ordered(2);    
    
    cout << set1 << endl;
    if(set1.in(2)) {
        cout << "in set" << endl;
    }
    else {
        cout << "not in set" << endl;
    }

    set1.insert_ordered(3);  
        set1.insert_ordered(3);  
            set1.insert_ordered(3);  
                set1.insert_ordered(3);  
                    set1.insert_ordered(3);  
                        set1.insert_ordered(3);  
        // set1.insert_ordered(3);   
        //     set1.insert_ordered(3);   
        //         set1.insert_ordered(3);   
        //             set1.insert_ordered(3);     
    // set1.add(3);
    //     set1.add(3);
    //         set1.add(3);
    //     set1.add(4);
    //         set1.add(4);
    // set1.add(4);

cout << set1 << endl; 
    if(set1.in(3)) {
        cout << "in set" << endl;
    }
    else {
        cout << "not in set" << endl;
    }   
    cout << set1 << endl;
}