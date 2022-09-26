#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;

#include "arithmeticExpression.h"



int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

arithmeticExpression::arithmeticExpression(const string &expression){
    infixExpression = expression;
    root = nullptr;
}

/* Converts the infixExpression to its equivalent postfix string
       and then generates the tree and assigns the root node to the 
       root data field. The key for the first node is 'a', 'b' for the second node and so on. */
void arithmeticExpression::buildTree(){
    string postfix = infix_to_postfix();
    stack<TreeNode*> stack;
    char c;
    char key = 'a';
 
    for(unsigned int i = 0; i < postfix.size(); i++){
        c = postfix.at(i);
        TreeNode* temp = new TreeNode(c, key + i);
        if(priority(c) > 0){
            temp->right = stack.top();
            stack.pop();
            temp->left = stack.top();
            stack.pop();
            stack.push(temp);
            root = temp;
        }
        else{
            stack.push(temp);
        }
    }
}

/* Calls the recursive infix function. */
void arithmeticExpression::infix(){
    infix(root);
}

/* Calls the recursive prefix function. */
void arithmeticExpression::prefix(){
    prefix(root);
}

/* Calls the recursive postfix function. */
void arithmeticExpression::postfix(){
    postfix(root);
}

void arithmeticExpression::visualizeTree(ofstream &file, TreeNode *root){  
}

/* Helper function that outputs the infix notation of the arithmetic expression tree
       by performing the inorder traversal of the tree.
       An opening and closing parenthesis must be added at the 
       beginning and ending of each expression. */
void arithmeticExpression::infix(TreeNode *root){
//left root right
  if(root != nullptr){
    if(root->left != nullptr){
        cout << '(';
    }

    infix(root->left);
    cout << root->data;
    infix(root->right);

    if(root->right != nullptr){
      cout << ')';
    }
  }
}

/* Helper function that outputs the prefix notation of the arithmetic expression tree
       by performing the preorder traversal of the tree. */
 void arithmeticExpression::prefix(TreeNode *root){
    //ROOT LEFT RIGHT
    if (root != nullptr) {
        cout << root->data;
        prefix(root->left);
        prefix(root->right);
    }    
}

/* Helper function that outputs the postfix notation of the arithmetic expression tree
       by performing the postorder traversal of the tree. */
void arithmeticExpression::postfix(TreeNode *root){
    //left right node
    if (root!= nullptr) {
        postfix(root->left);
        postfix(root->right);
        cout << root->data;
    }
}