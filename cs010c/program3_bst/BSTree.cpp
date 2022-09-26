#include "BSTree.h"
#include <iostream>
#include <string>
using namespace std;

BSTree::BSTree(){
  root = nullptr;
}

void BSTree::insert(const string &data) {
	Node* newNode = new Node();
  newNode->sentence = data;	
  if (root == nullptr) {
		root = newNode;
		return;
	}
	Node* currNode = root;
	Node* parentNode = nullptr;
	while (currNode != nullptr) {
		parentNode = currNode;
		if (newNode->sentence < currNode->sentence) {
			currNode = currNode->left;
		}
		else if (newNode->sentence > currNode->sentence){
			currNode = currNode->right;
		}
		else {
			currNode->count += 1;
			return;
		}
	}
	if (newNode->sentence< parentNode->sentence) {
		parentNode->left = newNode;
		newNode->parent = parentNode;
	}
	else {
		parentNode->right = newNode;
		newNode->parent = parentNode;
	}
}  

void BSTree::remove(const string &data) {
	Node* searchedNode = search(data, root);
	
	if (root == nullptr) {
		return;
	}
	
	if (searchedNode == nullptr) {
		return;
	}
	
	if (searchedNode->count > 1) {
		searchedNode->count -= 1;
		return;
	}
	
	removeNode(searchedNode, data);
}

void BSTree::removeNode(Node* node, string data) {
	 Node* parentNode = node->parent;
	
	if (node->left == nullptr && node->right == nullptr) {
		if (parentNode == nullptr) {
			root = nullptr;
		}
		else if (parentNode->left == node) {
			parentNode->left = nullptr;
		}
		else {
			parentNode->right = nullptr;
		}
		delete node;
		return;
	}
	else if (node->left == nullptr) {
		Node* successor = findSuccessor(node);
		node->sentence = successor->sentence;
		node->count = successor->count;
		if (successor->count > 1) {
			successor->count -= 1;
		}
		removeNode(successor, successor->sentence);
		return;
	}
	else {
		Node* predecessor = findPredecessor(node);
		node->sentence = predecessor->sentence;
		node->count = predecessor->count;
		if (predecessor->count > 1) {
			predecessor->count -= 1;
		}
		removeNode(predecessor, predecessor->sentence);
		return;
	}
}

Node* BSTree::findSuccessor(Node* node) const {
	if (node->right != nullptr) {
		Node* currNode = node->right;
		while (currNode->left != nullptr) {
			currNode = currNode->left;
		}
		return currNode;
	}
	return nullptr;
}

Node* BSTree::findPredecessor(Node* node) const {
	if (node->left != nullptr) {
		Node* currNode = node->left;
		while (currNode->right != nullptr) {
			currNode = currNode->right;
		}
		return currNode;
	}
	return nullptr;
}


bool BSTree::search(const string& key) const {
	return search(key, root);
}

Node* BSTree::search(const string &key, Node* curr) const {
    if(curr != 0) {
        if(key == curr->getSentence()) {
            return curr;
        }
        else {
            if(key < curr->getSentence()) {
                return search(key, curr->left);
            }
            else {
                return search(key, curr->right);
            }
        }
    }
    else {
        return nullptr;
    }
}

/* Find and return the largest value in the tree. 
Return an empty string if the tree is empty */
string BSTree::largest() const{
  Node* curr = root;
  if (curr == nullptr){
    return "";
  }
  while (curr->right != nullptr){
    curr = curr->right;
  }
  return curr->getSentence();
}

/* Find and return the smallest value in the tree. 
Return an emtpy string if the tree is empty */
string BSTree::smallest() const{
  Node* curr = root;
  if (curr == nullptr){
    return "";
  }
  while (curr->left != nullptr){
    curr = curr->left;
  }
  return curr->getSentence();
}

/* Compute and return the height of a particular string in the tree. 
The height of a leaf node is 0 (count the number of edges on the longest path). 
Return -1 if the string does not exist. 
*/

int BSTree::height(const string &data) const {
    if(!search(data)) {
        return -1;
    }
    Node *curr = search(data, root);
    Node *currLeft = curr;
    Node *currRight = curr;
    int leftCnt = 0;
    int rightCnt = 0;
    
    if(curr->left != 0) {
        currLeft = currLeft->left;
        leftCnt++;
        leftCnt = leftCnt + height(currLeft->sentence);
    }
    if(curr->right != 0) {
        currRight = currRight->right;
        rightCnt++;
        rightCnt = rightCnt + height(currRight->sentence);
    }
    if(leftCnt >= rightCnt) {
        return leftCnt;
    }
    else {
        return rightCnt;
    }
}

/* Printing */
/* For all printing orders, each node should be displayed as follows:
<string> (<count>)
e.g. goodbye(1), Hello World(3)
*/
void BSTree::preOrder() { 
  preOrder(root);
  cout << endl;
}

void BSTree::postOrder(){
  postOrder(root);
  cout << endl;
}

void BSTree::inOrder() {
  inOrder(root);
  cout << endl;
}

void BSTree::preOrder(Node *curr){ 
  if (curr != nullptr){
    cout << curr->getSentence() << "(";
    cout << curr->getCount() << "), "; 
    preOrder(curr->left);
    preOrder(curr->right);
  }
}

void BSTree::postOrder(Node *curr){ 
  if (curr != nullptr){
    postOrder(curr->left);
    postOrder(curr->right);
    cout << curr->getSentence() << "(";
    cout << curr->getCount() << "), ";
  }
}

void BSTree::inOrder(Node *curr){ 
  if (curr != nullptr){
    inOrder(curr->left);
    cout << curr->getSentence() << "(";
    cout << curr->getCount() << "), ";
    inOrder(curr->right);
  }
}
