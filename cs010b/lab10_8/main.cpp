#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

   int testNum;
   
   cout << "Enter test number: ";
   cin >> testNum;
   cout << endl;
   
   if (testNum == 1) {
      IntList test1;
      test1.push_front(-3);
      test1.push_front(-2);
      test1.push_front(-1);
      test1.push_front(0);
      test1.push_front(1);
      test1.push_front(2);
      test1.push_front(3);
      test1.push_front(4);
      cout << "Before: " << test1 << endl;
      test1.bubbleUp();
      cout << "After : " << test1 << endl;    
   }
   
   if (testNum == 2) {
      IntList test2;
      test2.push_front(3);
      test2.push_front(4);
      test2.push_front(6);
      test2.push_front(1);
      test2.push_front(7);
      test2.push_front(5);
      cout << "Before: " << test2 << endl;
      test2.bubbleUp();
      cout << "After : " << test2 << endl;  
   }
   
   if (testNum == 3) {
      IntList test3;
      test3.push_front(10);
      test3.push_front(9);
      test3.push_front(8);
      test3.push_front(7);
      test3.push_front(6);
      test3.push_front(5);
      test3.push_front(4);
      test3.push_front(3);
      test3.push_front(2);
      test3.push_front(1);
      cout << "Before: " << test3 << endl;
      test3.bubbleUp();
      cout << "After : " << test3 << endl;  
   }   

   if (testNum == 4) {
      IntList test4;
      test4.push_front(2);
      test4.push_front(6);
      test4.push_front(5);
      test4.push_front(4);
      test4.push_front(3);
      test4.push_front(1);
      cout << "Before: " << test4 << endl;
      test4.bubbleUp();
      cout << "After : " << test4 << endl;  
   }
   
   // This test shows how calling bubbleUp until no more bubbling occurs
   // can be used to sort the list.
   if (testNum == 5) {
      IntList test4;
      test4.push_front(2);
      test4.push_front(7);
      test4.push_front(3);
      test4.push_front(5);
      test4.push_front(2);
      test4.push_front(4);
      cout << "Before: " << test4 << endl;
      // Keep bubbling until there are no more swaps (list is sorted)
      while (test4.bubbleUp());
      cout << "After : " << test4 << endl;  
   }

   return 0;
}
