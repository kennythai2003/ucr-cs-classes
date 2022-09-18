#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
	int value;
	IntNode *next;
	IntNode(int value) : value(value), next(nullptr) { }
};


class IntList {
 private:
	IntNode *head;
	IntNode *tail;
 public:
	IntList();
	~IntList();
	void push_front(int);
	void pop_front();
	bool empty() const;
	const int & front() const;
	const int & back() const;
	friend ostream & operator<<(ostream &, const IntList &);

	IntList(const IntList &cpy); 
	//the copy constructor. Make sure this performs deep copy.
	IntList & operator=(const IntList &rhs); 
	// the overloaded assignment operator. Make sure this performs deep copy.
	void push_back(int value);
	//Inserts a data value (within a new node) at the back end of the list.
	void clear(); 
	// Removes (deallocates) all IntNodes in the IntList. Don't forget to set 
	//both head and tail to appropriate values for an empty list. DO NOT leave them dangling!
	void selection_sort();
	//Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
	void insert_ordered(int value);
	 //Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted 
	 //in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.) 
	 //This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.
	void remove_duplicates();
	 //Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list.
};

#endif
