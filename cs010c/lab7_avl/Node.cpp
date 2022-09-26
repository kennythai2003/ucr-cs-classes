#include <iostream>
using namespace std;

#include "Node.h"

Node::Node(string data){
  this->data = data;
  balanceFactor = 0;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}