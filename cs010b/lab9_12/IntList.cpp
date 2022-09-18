#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

bool IntList::exists(IntNode *head, int desiredValue) const {
   if (head == nullptr) {
      return false;
   }
   if (head-> value == desiredValue) {
      return true;
   }

   //goes through list and if value is found b4 null then true
   return exists(head->next, desiredValue);
}

bool IntList::exists(int desiredValue) const {
   if (head == nullptr) {
      return false;
   }
   if (head->value == desiredValue) {
      return true;
   }

   //we dont have a list to go through so we recursively call the other function
   return exists(head->next, desiredValue);
}

ostream & operator<<(ostream &out, const IntList &node){
   if (node.head == nullptr) {
      //checking 4 an empty list
      return out;
   }

   //bc we cant use x->next we need to recursively call the other
   // << function to go through the nodes 4 us
   operator<<(out, node.head);
   
   return out;
}

ostream & operator<<(ostream &out, IntNode *currValue){
   if(currValue == nullptr){
      //accounts 4 when the list ends
      return out;
   }
   out << currValue->value;
   if(currValue->next != nullptr){
      //accounting 4 the last number not having a space
      out << ' ';
   }

   //outputs current node value

   //recursive call until node is null
   operator<<(out, currValue->next);

   return out;
}