#include <iostream>
#include "Bst.h"
using namespace std;

int main(){

    Bst bst;
    bst.insert(50);
    bst.insert(20);
    bst.insert(30);
    bst.insert(60);
    bst.insert(90);
    cout<<bst.findMax()<<endl;
    cout<<bst.findMin()<<endl;
    bst.remove(50);
    bst.inorder();
    bst.rootdata();
    cout<<bst.height()<<endl;

    return 0;
}