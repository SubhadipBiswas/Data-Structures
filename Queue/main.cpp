#include <iostream>
#include "queue.h"

using namespace std;

int main(){

    Queue kfc(5);

    kfc.enQueue(1);
    kfc.enQueue(2);
    kfc.enQueue(3);
    kfc.enQueue(4);
    kfc.enQueue(5);
    kfc.deQueue();
    kfc.deQueue();
    kfc.deQueue();
    kfc.deQueue();
    kfc.deQueue();
    kfc.printQueue();
    cout<<kfc.getFront()<<endl;
    cout<<kfc.getBack()<<endl;
    cout<<kfc.IsEmpty()<<endl;

    return 0;
}