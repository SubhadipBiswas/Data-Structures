#include <iostream>
#include "binaryheap.h"
using namespace std;

BinaryHeap::BinaryHeap(int size){
    capacity = size;
    length = 0;
    arr = new int[capacity];
}

void BinaryHeap::insert(int data){
    if(length>=capacity){
        cout<<"Sorry! Can't insert. The heap is full"<<endl;
        return ;
    }

    arr[length] = data;
    length++;

    int idx = length - 1;
    while(idx != 0 && arr[parent(idx)]<arr[idx]){
        swap(&arr[parent(idx)], &arr[idx]);
        idx = parent(idx);
    }
}

int BinaryHeap::getMax(){
    if(length != 0){
        return arr[0];
    }
    return INT32_MAX;
}

int BinaryHeap::parent(int index){
    return (index-1)/2;
}

int BinaryHeap::lchild(int index){
    return 2*index +1;
}

int BinaryHeap::rchild(int index){
    return 2*index+2;
}

void BinaryHeap::swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void BinaryHeap::heapify(int index){
    int left = lchild(index);
    int right = rchild(index);
    int current = index;

    if(left<=length && arr[left]>arr[current]){
        current = left;
    }

    if(right<=length && arr[right]>arr[current]){
        current = right;
    }

    if(current != index){
        int temp = arr[index];
        arr[index] = arr[current];
        arr[current] = temp;
        heapify(current);
    }
}

int BinaryHeap::extractMax(){
    int max = arr[0];
    arr[0] = arr[length-1];
    length--;

    heapify(0);
    return max;
}

void BinaryHeap::printHeap(){
    for(int i=0;i<length;i++){
        std::cout<<arr[i]<<",";
    }
    std::cout<<std::endl;
}
