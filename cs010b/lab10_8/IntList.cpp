#include "IntList.h"

bool IntList::bubbleUp() {
   bool x = false;
   if (head == nullptr || head->next == nullptr) {
      return false;
   } 
      x = bubbleUp(head->next);
      if (head->value > head->next->value) {
         swap(head->value, head->next->value);
         x = true;
      }
   return x;
}
bool IntList::bubbleUp(IntNode *curr) {
   bool x = false;
   if (curr->next == nullptr) {
      return x;
   } 

   x = bubbleUp(curr->next);

   if (curr->value > curr->next->value) {
      swap(curr->value, curr->next->value);
      x = true;
   }

   return x;
}

