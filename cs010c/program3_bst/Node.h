#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
using namespace std;

class Node{
  friend class BSTree;
  private:
    int count;
    string sentence;
  public:
  //constructors
    Node(); 
    Node(string, int);
    //left & right childs
    Node *left;
    Node *right;
    Node * parent;
    //accessors
    int getCount();
    string getSentence();
    //mutators
    void setCount(int);
    void setSentence(string);
};
#endif 