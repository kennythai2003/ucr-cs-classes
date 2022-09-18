#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <ostream>

using namespace std;

struct IntNode {
    int value;
    IntNode *next;
    IntNode(int val) : value(val), next(nullptr) {}
};

class IntList {

 private:
   IntNode *head;

 public:

   /* Initializes an empty list.
   */
   IntList() : head(nullptr) {}

   /* Inserts a data value to the front of the list.
   */
   void push_front(int val) {
      if (!head) {
         head = new IntNode(val);
      } else {
         IntNode *temp = new IntNode(val);
         temp->next = head;
         head = temp;
      }  
   }
   
   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
   friend ostream & operator<<(ostream &out, const IntList &rhs) {
      if (rhs.head) {
         IntNode *curr = rhs.head;
         out << curr->value;
         for (curr = curr->next ; curr ; curr = curr->next) {
            out << ' ' << curr->value;
         }
      }
      return out;
   }
   
   
   /* Starting from the back of the list this function "bubbles up" values smaller than the value that comes before it
      such that the smallest value in the list will end up at the front of the list.
      The function returns true if any value bubbled up. It returns false if no value was moved by the function. 
      Works by calling a recursive function (defined below).
   */
   bool bubbleUp();

 private:


   /* Recursive helper functions that will (1) go to the back of the list and then 
      (2) recursively bubble up smaller values (values smaller than the value preceding it in the list).
      If any value in the list is swapped, the function should return true, otherwise return false.
   */
   bool bubbleUp(IntNode *);
};



#endif