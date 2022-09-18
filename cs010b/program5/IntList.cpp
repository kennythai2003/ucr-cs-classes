#include "IntList.h"
using namespace std;

//CHECK FOR CASES: empty list; when next goes towards an empty list; head & tail
 
IntList::~IntList() {
    while (head != nullptr) {
        IntNode *temp; 
        temp = head->next;
        delete head;
        head = temp;
    }
}

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

void IntList::push_front(int val) {
    IntNode *temp = new IntNode(val);
    temp->next = head; 
    head = temp;
    
    if (tail == nullptr) {
        tail = head;
    }       
}

void IntList::pop_front() {
    if (!empty()) {
        IntNode *temp = head->next;
        delete head;
        head = temp;
    }

    if (head == nullptr) {
        tail = nullptr;
    }
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

IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    IntNode *curr = cpy.head;
    while (curr != nullptr) {
        push_back(curr->value);
        curr = curr->next; 
    }
}

IntList & IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        clear();
        IntNode *curr = rhs.head;
        while (curr != nullptr) {
            push_back(curr->value);
            curr = curr->next; 
        }
    }
    return *this;
}

void IntList::push_back(int value){
    IntNode *temp = new IntNode(value);
    if (empty()) {
        head = temp;
        tail = temp;
    }
    else if (head == tail) {
        tail = temp;
        head->next = tail;
    }
    else {
        tail->next = temp;
        tail = temp; 
    }
}

void IntList::clear() {
    IntNode *temp;
    if (empty()) {
        head = nullptr;
        tail = nullptr;
    }
    while (head != nullptr) {
        temp = head -> next;
        delete head;
        head = temp;
    }
    tail = nullptr; 
}

void IntList::selection_sort() {
    //algorithm derived from Selection Sort Video & 10.6 Code
    for (IntNode *i = head; i != nullptr; i = i-> next) {
        IntNode *min = i; 
        for (IntNode *j = i->next; j != nullptr; j = j-> next) {
            if (j->value < min->value) {
                swap (min->value, j->value);
            }
        }
    }
}

void IntList::insert_ordered(int value) {
    IntNode *temp = new IntNode (value);

    if (empty()) {
        head = temp;
        tail = temp;
    }
    else if (value <= head->value) {
        push_front(temp->value);
    }
    else if (value >= tail->value) {
        push_back(temp->value);
    }
    else {
        for (IntNode *prev = head; prev->value < value; prev = prev->next) {
            IntNode *curr = prev->next;
            if (curr->value >= value) {
                prev->next = temp;
                temp->next = curr;
            }
        }
    }
}

void IntList::remove_duplicates() {
    for (IntNode *i = head; i != nullptr; i = i-> next) {
        IntNode *prev = i;
        IntNode *curr = prev->next;
        while (curr != nullptr) {
            if (curr->value == i->value) {
                if (curr == tail) {
                    prev->next = nullptr;
                    tail = prev;
                    delete curr; 
                    curr = prev->next;
                }
                else {
                    prev->next = curr->next;
                    delete curr; 
                    curr = prev-> next;
                }
            }
            else {
                curr = curr->next;
                prev = prev->next;
            }
        }
    }
}

