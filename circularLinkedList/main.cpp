#include <iostream>
#include "linkedlist.h"
using namespace std;

int main(){
    LinkedList player;
    player.Insert(5);
    player.Insert(6);
    player.Insert(7);
    player.Insert(8);
    player.Insert(9);
    player.Delete(7);
    player.Items();
    player.Length();
    return 0;
}