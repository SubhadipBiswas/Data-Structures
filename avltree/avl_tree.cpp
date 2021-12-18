#include <iostream>
#include "avl_tree.h"

AVLTree::AVLTree(){
    root = NULL;
}

int AVLTree::height(Node* curr){
    if(curr == NULL){
        return -1;
    }
    int lheight = height(curr->left);
    int rheight = height(curr->right);
    if(lheight>rheight){
        return lheight + 1;
    }
    else{
        return rheight + 1;
    }
}

int AVLTree::balancefactor(Node* curr){
    if(curr->left && curr->right){
        return (height(curr->left)-height(curr->right));
    }
    else if(curr->left && curr->right == NULL){
        return height(curr->left);
    }
    else if(curr->left == NULL && curr->right){
        return height(curr->right);
    }
}

Node* AVLTree::llrotation(Node* curr){
    Node* tmp;
    Node* tmp2;

    tmp = curr;
    tmp2 = tmp->left;

    tmp->left = tmp2->right;
    tmp2->right = tmp;

    return tmp2; 
}

Node* AVLTree::rrrotation(Node* curr){
    Node* tmp;
    Node* tmp2;

    tmp = curr;
    tmp2 = tmp->right;

    tmp->right = tmp2->left;
    tmp2->left = tmp;

    return tmp2;
}

Node* AVLTree::rlrotation(Node* curr){
    Node* tmp;
    Node* tmp2;
    Node* tmp3;

    tmp = curr;
    tmp2 = tmp->right;
    tmp3 = tmp->right->left;

    tmp->right = tmp3->left;
    tmp2->left = tmp3->right;
    tmp3->left = tmp;
    tmp3->right = tmp2;

    return tmp3;
}

Node* AVLTree::lrrotation(Node* curr){
    Node* tmp;
    Node* tmp2;
    Node* tmp3;

    tmp = curr;
    tmp2 = tmp->left;
    tmp3 = tmp->left->right;

    tmp->left = tmp3->right;
    tmp2->right = tmp3->left;
    tmp3->right = tmp;
    tmp3->left = tmp2;

    return tmp3;
}

Node* AVLTree::insert(Node* curr, int val){
    if(curr==NULL){
        Node* temp = new Node();
        temp->data = val;
        curr = temp;
        curr->left=curr->right=NULL;
        return curr;
    }
    else{
        if(val<curr->data){
            curr->left = insert(curr->left,val);
        }
        else{
            curr->right = insert(curr->right,val);
        }
    }

    if(balancefactor(curr)==2 && balancefactor(curr->left)==1){
        curr = llrotation(curr);
    }
    else if(balancefactor(curr)==-2 && balancefactor(curr->right)==-1){
        curr = rrrotation(curr);
    }
    else if(balancefactor(curr)==-2 && balancefactor(curr->right)==1){
        curr = rlrotation(curr);
    }
    else if(balancefactor(curr)==2 && balancefactor(curr->left)==-1){
        curr = lrrotation(curr);
    }

    return curr;
}

void AVLTree::insert(int val){
    root = insert(root,val);
}

Node* AVLTree::findMax(Node* curr){
    while(curr->right !=NULL){
        curr = curr->right;
    }
    return curr;
}

Node* AVLTree::findMin(Node* curr){
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node* AVLTree::remove(Node* curr, int val){

    if(curr->left == NULL && curr->right == NULL){
            if(curr==this->root){
                this->root = NULL;
            }
            delete curr;
            return NULL;
        }


        Node* temp;
        if(curr->data < val){
            curr->right = remove(curr->right,val);
        }
        else if(curr->data > val){
            curr->left = remove(curr->left,val);
        }
        else{
            if(curr->left != NULL){
                temp = findMax(curr->left);
                curr->data = temp->data;
                curr->left=remove(curr->left,temp->data);
            }
            else{
                temp = findMin(curr->right);
                curr->data = temp->data;
                curr->right = remove(curr->right,temp->data);
            }
        }

        if(balancefactor(curr)==2 && balancefactor(curr->left)==1){ curr = llrotation(curr); }                  
        else if(balancefactor(curr)==2 && balancefactor(curr->left)==-1){ curr = lrrotation(curr); }
        else if(balancefactor(curr)==2 && balancefactor(curr->left)==0){ curr = llrotation(curr); }
        else if(balancefactor(curr)==-2 && balancefactor(curr->right)==-1){ curr = rrrotation(curr); }
        else if(balancefactor(curr)==-2 && balancefactor(curr->right)==1){ curr = rlrotation(curr); }
        else if(balancefactor(curr)==-2 && balancefactor(curr->right)==0){ curr = rrrotation(curr); }

        
        return curr;
    }

void AVLTree::remove(int val){
    root = remove(root,val);
}

void AVLTree::inorder(Node* curr){
    if(curr==NULL){
        return ;
    }
    inorder(curr->left);
    std::cout<<curr->data<<",";
    inorder(curr->right);
}

void AVLTree::inorder(){
    Node* curr = root;
    inorder(curr);
    std::cout<<std::endl;
}