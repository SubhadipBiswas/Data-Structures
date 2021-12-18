#include <iostream>
#include "stack.h"

using namespace std;

int main(){

    Stack player(5);
    player.push(1);
    player.push(2);
    player.push(3);
    player.pop();
    cout<<player.getTop()<<endl;
    cout<<player.getSize()<<endl;
    cout<<player.IsEmpty()<<endl;
    player.printStack();
    return 0;
}