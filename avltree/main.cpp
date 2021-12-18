#include <iostream>
#include "avl_tree.cpp"

using namespace std;

int main(){

    AVLTree game;
    game.insert(20);
    game.insert(15);
    game.insert(10);
    game.insert(30);
    game.insert(45);
    game.insert(47);
    game.remove(30);
    game.remove(47);
    game.remove(10);
    game.inorder();
    return 0;
}