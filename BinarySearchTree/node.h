#include <iostream>

struct Node{
    Node(int data);
    Node* left;
    Node* right;
    int data;
};

Node::Node(int data){
    left = NULL;
    right=NULL;
    this->data = data;
}