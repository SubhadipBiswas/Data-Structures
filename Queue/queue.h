#include <iostream>

using namespace std;

class Queue{
public:
    Queue(int sz);
    void enQueue(int data);
    void deQueue();
    int getFront(){return front;}
    int getBack(){return back;}
    bool IsEmpty();
    void printQueue();
private:
    int size;
    int length;
    int front;
    int back;
    int* queueArr;
};

Queue::Queue(int sz){
    size= sz;
    length = 0;
    front = -1;
    back= -1;
    queueArr = new int[sz]{};
}

void Queue::enQueue(int data){
    if(length == size){
        cout<<"Queue overflow"<<endl;
    }
    else{
        if(front == -1){
            queueArr[length] = data;
            front = queueArr[length];
            back = queueArr[length];
            length++;
        }
        else{
            queueArr[length] = data;
            back = queueArr[length];
            length++;
        }
    }
}

void Queue::deQueue(){
    if(front==-1){
        cout<<"Queue underflow"<<endl;
    }
    else{
        for(int i =0;i<length-1;i++){
            queueArr[i] = queueArr[i+1];
        }
        length--;
        if(length==0){
            front=-1;
            back = -1;
        }
        else{
            front = queueArr[0];
            back = queueArr[length-1];
        }
    }
}

bool Queue::IsEmpty(){
    if(front==-1){
        return true;
    }
    else{
        return false;
    }
}

void Queue::printQueue(){
    if(length !=0){
        for(int i=0;i<length;i++){
        cout<<queueArr[i]<<",";
        }
        cout<<endl;
    }
    else{
        cout<<"Queue underflow"<<endl;
    }
}