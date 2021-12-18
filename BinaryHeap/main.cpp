#include <iostream>
#include "binaryheap.cpp"

using namespace std;

int main(){
    BinaryHeap heap(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(10);
    heap.insert(7);
    heap.insert(20);
    heap.extractMax();
    heap.printHeap();
    cout<<heap.getMax()<<endl;
    return 0;
}