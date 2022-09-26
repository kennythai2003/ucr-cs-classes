#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class AVLTree{
  private:
    Node* root;

  public:
    AVLTree();
    void insert(const string &);
    int balanceFactor(Node*);
    void printBalanceFactors();
    // void visualizeTree(const string &);
    // void rebalance(Node*);
  private:
    Node* findUnbalancedNode(Node*, const string &v);
    void rotate (Node*);
    void setBalanceFactor(Node*);
    void rotateRight (Node* n);
    void insert(Node*, Node*);
    void rotateLeft(Node* n);
    void printBalanceFactors(Node *);
    int height(Node*) const;
    // void setChild(Node*,string,Node*);
    // void replaceChild(Node*,Node*,Node*);
    
};
#endif