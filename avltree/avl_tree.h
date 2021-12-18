#include <iostream>
#include "node.h"

class AVLTree{
public:
    AVLTree();
    void insert(int val);
    void remove(int val);
    void inorder();
private:
    Node* root;
    int height(Node* curr);
    int balancefactor(Node* curr);
    Node* llrotation(Node* curr);
    Node* rrrotation(Node* curr);
    Node* rlrotation(Node* curr);
    Node* lrrotation(Node* curr);
    Node* insert(Node* curr, int val);
    Node* findMax(Node* curr);
    Node* findMin(Node* curr);
    Node* remove(Node*curr, int val);
    void inorder(Node* curr);
};
