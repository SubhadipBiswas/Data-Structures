#include "node.h"
#include <iostream>

using namespace std;

class Bst
{
private:
    Node* root;
    void insert(Node* curr, int data);
    Node* remove(Node* curr, int data);
    Node* findMin(Node* curr);
    void inorder(Node* curr);
    int height(Node* curr);
public:
    Bst();
    int findMin();
    int findMax();
    void insert(int data);
    void remove(int data);
    void inorder();
    void rootdata();
    int height();
};

Bst::Bst(){
    root = NULL;
}

void Bst::insert(Node* curr,int data){
    if(data>curr->data){
        if(!curr->right){
            curr->right = new Node(data);
        }
        else{
            insert(curr->right,data);
        }
    }
    else{
        if(!curr->left){
            curr->left = new Node(data);
        }
        else{
            insert(curr->left,data);
        }
    }
}

void Bst::insert(int data){
    if (root == NULL){
        root = new Node(data);
    }
    else{
        insert(root,data);
    }
}


int Bst::findMax(){
    Node* curr = root;
    while(curr->right){
        curr = curr->right;
    }
    return curr->data;
}

Node* Bst::findMin(Node* curr){
    while(curr->left){
        curr = curr->left;
    }
    return curr;
}

int Bst::findMin(){
    Node* curr = root;
    while(curr->left){
        curr= curr->left;
    } 
    return curr->data;
}

Node* Bst::remove(Node* curr, int data){

    if(curr==NULL){
        return curr;
    }
    else if(data<curr->data){
        curr->left = remove(curr->left,data);
    }
    else if(data>curr->data){
        curr->right = remove(curr->right,data);
    }
    else{
        if(curr->left == NULL && curr->right==NULL){
            delete curr;
            curr = NULL;
        }
        else if(curr->left == NULL){
            Node* temp = curr;
            curr = curr->right;
            delete temp;
        }
        else if(curr->right == NULL){
            Node* temp = curr;
            curr = curr->left;
            delete temp;
        }
        else{
            Node* temp = findMin(curr->right);
            curr->data = temp->data;
            curr->right = remove(curr->right,temp->data);
        }
    }
    return curr;
}

void Bst::remove(int data){
    Node* curr = root;
    remove(curr,data);
}

void Bst::inorder(Node* curr){
    if(curr==NULL){
        return ;
    }
    else{
        inorder(curr->left);
        cout<<curr->data<<",";
        inorder(curr->right);
    }
}

void Bst::inorder(){
    Node* curr = root;
    inorder(curr);
    cout<<endl;
}

void Bst::rootdata(){
    cout<<root->data<<endl;
}

int Bst::height(Node* curr){
    if (curr == NULL){
        return -1;
    }
    else{
        int lheight = height(curr->left);
        int rheight = height(curr->right);
        if (lheight>rheight){
            return lheight+1;
        } else{
            return rheight+ 1;
        }
    }
}

int Bst::height(){
    Node* curr = root;
    return height(curr);
}