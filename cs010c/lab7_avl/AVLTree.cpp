#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "AVLTree.h"
using namespace std;

AVLTree::AVLTree(){
    root = nullptr;
}

void AVLTree::insert(const string &sent) {
    Node *newNode = new Node(sent); 
    insert(root,newNode);
} 
// void AVLTree::insert(){

// }
// void AVLTree::insert(const string &data){
//     Node* newNode = new Node(data);
//     Node* curr = root;
//     if (root == nullptr){
//         root = newNode;
//         root->balanceFactor = 0;
//         return;
//     }

//     Node* parentCurr; 
//     while (curr != nullptr) {
//         //traverse down tree to find where newNode belongs
//         parentCurr = curr;
//         if (newNode->data == parentCurr->data){
//             return; 
//         }
//         else if (newNode->data < parentCurr->data){
//             //less continues to traverse down left
//             curr = curr->left;
//         }
//         else{
//             //more continnues to traverse down right
//             curr = curr->right;
//         }
//     }
//     if (newNode->data < parentCurr->data){
//         //case where new node is less than current parent
//         //set parent left to newnode, set newnode parent to parent
//         parentCurr->left = newNode;
//         newNode->parent = parentCurr;
//     }
//     if (newNode->data >parentCurr->data){
//         parentCurr->right = newNode;
//         newNode->parent = parentCurr;
//     }
//     setBalanceFactor(root);
// }

// //helper for insert
// void AVLTree::setBalanceFactor(Node* curr) {
// 	if (curr != nullptr) {
// 		curr->balanceFactor = balanceFactor(curr);
// 		setBalanceFactor(curr->left);
// 		setBalanceFactor(curr->right);
// 	}
// }

int AVLTree::balanceFactor(Node* curr){
    return height(curr->left) - height(curr->right);
}

// void AVLTree::printBalanceFactors(){

// }

// void AVLTree::visualizeTree(const string &){

// }

Node* AVLTree::findUnbalancedNode(Node*, const string &sent){
  Node* curr = root;
  Node* imbalance = nullptr;
  while(curr != nullptr){
    int balance = balanceFactor(curr);
    if(balance < -1 || balance > 1){
      imbalance = curr;
    }
    if(curr->data > sent){
      curr = curr->left;
    }
    else{
      curr = curr->right;
    }
  }
  return imbalance;
}

void AVLTree::rotate(Node* curr){
    if (balanceFactor(curr) >= 2) {
        if (balanceFactor(curr->left) == -1){
            //crooked left, need to perform left right rottation
            rotateLeft(curr->left);
        }
            //left heavy 
        rotateRight(curr);
    }
    if(balanceFactor(curr) <= -2) {
        if (balanceFactor(curr->right) == 1){
            //crooked right, need to perform right left rotation
            rotateRight(curr->right);
        }
        //right heavy
        rotateLeft(curr);
    }
}

void AVLTree::rotateLeft (Node* curr){
    Node *parent = curr->parent;
    Node* rightChild = curr->right;
    Node* succ = rightChild->left;
    if (parent == nullptr){
        root = rightChild;
    }
    else {
        if (parent->data > curr->data) {
            //update parent's left if curr is less than it
            parent->left = rightChild;
        }
        if (parent-> data < curr->data){
            //update parent's right if curr is greater than it
            parent->right = rightChild;
        }
    }
    rightChild->left = curr;
    curr->right = succ;
    rightChild->parent = curr->parent;
    curr->parent = rightChild;
}

void AVLTree::insert(Node*curr, Node*newNode){
if (!root) {
      root = newNode; 
      root->parent = 0;
      return;
   }
   curr = root;
   while (curr) { 
      if (newNode->data == curr->data) {
          curr->balanceFactor = curr->balanceFactor + 1;
          curr = 0;
      } 
      else if (newNode->data < curr->data) {
         if (curr->left == 0) {
            curr->left = newNode;
            newNode->parent = curr;
            curr = 0;
         }
         else
            curr = curr->left;
      }
      else {
         if (curr->right == 0) {
            curr->right = newNode;
            newNode->parent = curr;
            curr = 0;
         }
         else
            curr = curr->right;
      }
   }

  newNode = newNode->parent;
  while (newNode) { 
      rotate(newNode); 
      newNode = newNode->parent; 
      
  }
}

void AVLTree::rotateRight(Node* curr){
	Node* parent = curr->parent;
	Node* leftChild = curr->left;
	Node* succ = leftChild->right;
	
	if (parent == nullptr) {
		root = leftChild;
	}
	else {
		if (parent->data > curr->data) {
			parent->left = leftChild;
		}
		else if (parent->data < curr->data){
			parent->right = leftChild;
		}
	}
	
	leftChild->right = curr;
	curr->left = succ;
	leftChild->parent = curr->parent;
	curr->parent = leftChild;
}

void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
    cout << endl;
}

void AVLTree::printBalanceFactors(Node *curr){
    if (curr != nullptr) {
        printBalanceFactors(curr->left);
        cout << curr->data << "(" << balanceFactor(curr) << "), ";
        printBalanceFactors(curr->right);
    }
}

int AVLTree::height(Node* curr) const{
    int left, right = 0;

    if (curr == nullptr){
        return -1; //accounts for left/right no node
    }
    else{
        left = height(curr->left); 
        right = height(curr->right);

        if (left > right) {
            return (left + 1);
        }
        else{
            return (right + 1);
        }
    }
}

// void AVLTree::setChild(Node*,string,Node*){

// }

// void AVLTree::replaceChild(Node*,Node*,Node*){

// }
    