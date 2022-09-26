#include "IntList.h"

IntList::IntList() {
    dummyHead = new IntNode(0); //initializes the node
    dummyTail = new IntNode(0); //initalizes the node
    dummyHead->next = dummyTail; //in an empty list there is only head and node
    dummyTail->prev = dummyHead; //^^
}
IntList::~IntList(){
    IntNode *temp = dummyHead;
    while (dummyHead != nullptr) {
        temp = dummyHead->next;
        delete dummyHead;
        dummyHead = temp;
    }
}

void IntList::push_front(int value){
    IntNode *newNode = new IntNode(value);
    IntNode *temp = dummyHead->next; //keeps the position of first node
    newNode->prev = dummyHead; //new firstnode prev is pointed to dummy
    newNode->next = temp;// new firstnode next is pointed to original first node
    dummyHead->next = newNode; //dummynode keeps track of the new first node
    temp->prev = newNode; //sits old first node previous to new first node
}

void IntList::pop_front(){
    if (!empty()) {
        IntNode *firstNode = dummyHead->next;
        dummyHead->next = firstNode->next;
        firstNode->next->prev = dummyHead;
        delete firstNode;
    }
}

void IntList::push_back(int value){
    IntNode *newNode = new IntNode(value);
    IntNode *temp = dummyTail->prev;
    newNode->next = dummyTail; //sets new last node next to dumtail
    dummyTail->prev = newNode; //sets dum tail to new last ndoe
    temp->next = newNode;  //sets old last node next ptr to new last node
    newNode->prev = temp; //sets new nodes prev ptr to old last node
}

void IntList::pop_back(){
    if (!empty()) {
        IntNode *lastNode = dummyTail->prev;
        dummyTail->prev = lastNode->prev;
        lastNode->prev->next = dummyTail;
        delete lastNode;
    }
}

bool IntList::empty() const {
    bool empty = false;
    if (dummyHead-> next == dummyTail && dummyTail->prev == dummyHead){
        empty = true;
    }
    return empty;
}

ostream & operator<<(ostream &out, const IntList&rhs){
    IntNode *curr = rhs.dummyHead;
    curr = curr->next;
    if (curr != rhs.dummyTail) {
        while (curr->next != rhs.dummyTail) {
            out << curr->data << " ";
            curr = curr->next;
        }
        out << curr->data;
    }
    return out;
}

void IntList::printReverse() const {
    IntNode *curr = dummyTail->prev;
    if (curr!= dummyHead) {
        while (curr->prev != dummyHead) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << curr->data;
    }
}
