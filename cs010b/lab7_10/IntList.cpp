#include "IntList.h"
using namespace std;

//CHECK FOR CASES: empty list; when next goes towards an empty list; head & tail
//ds
///ds/
//ds
IntList::~IntList() {
    while (head != nullptr) {
        IntNode *temp; 
        temp = head->next;
        delete head;
        head = temp;
    }
    //does destroyer delete all ndoes (test 5)

}
IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

void IntList::push_front(int val) {
    IntNode *temp = new IntNode(val);
    temp->next = head; //same notation as (*temp).next
    head = temp;

    //accounts for if there is only one node; removes possiblity of tail dangling
    if (tail == nullptr) {
        tail = head;
    }
        
}

void IntList::pop_front() {
    if (!empty()) {
        IntNode *temp = head->next;
        delete head; // removes first node (TEST 6)
        head = temp; //sets to the prior second node
    }

    //accounts for an empty list;
    if (head == nullptr) {
        tail = nullptr;
    }

    //are there any dangling pointers or potential memoru leaks
}

bool IntList::empty() const {
    bool empty = false;
    if (head == nullptr && tail == nullptr) {
        empty = true;
    }
    return empty;
}

const int & IntList::front() const {
    return head->value;
}

const int & IntList::back() const {
    return tail->value;
}

ostream & operator<<(ostream & out, const IntList & list) {
    IntNode *curr = list.head;
    while (curr != nullptr) {
        if(curr->next != nullptr) {
            //takes all values before the tail
            out << curr-> value << " ";
            curr = curr -> next;
        }
        else {
            //outputs tail value
            out << curr-> value; 
            curr = curr -> next;           
        }
    }
    return out;
}
