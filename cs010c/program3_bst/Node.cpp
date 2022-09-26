#include "Node.h"

#include <iostream>
#include <string>
using namespace std;

Node::Node() {
  count = 1;
  sentence = "";
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}

Node::Node(string sentence, int count) {
  this->count = count;
  this->sentence = sentence;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}

int Node::getCount(){
  return count;
}
string Node::getSentence(){
  return sentence;
}

void Node::setCount(int count){
  this->count = count;
}

void Node::setSentence(string sentence){
  this->sentence = sentence;
}