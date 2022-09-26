#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    int balanceFactor;
    Node* left;
    Node* right;
    Node* parent;
    Node(string);
};

#endif