#include <iostream>

using namespace std;

class Stack{
public:
    Stack(int sz);
    void push(int data);
    int pop();
    int getTop();
    int getSize();
    bool IsEmpty();
    void printStack();
private:
    int top;
    int size;
    int length;
    int* stackArr;
};

Stack::Stack(int sz){
    top = -1;
    size = sz;
    length = 0;
    stackArr = new int[size]{};
}

bool Stack::IsEmpty(){
    if (top == -1){
        return true;
    }
    return false;
}

void Stack::push(int data){
    if(length != size-1){
        stackArr[length] = data;
        length++;
        top = data;
    }
    else{
        cout<<"Stack Overflow"<<endl;
    }
}

int Stack::pop(){
    if(top==-1){
        return -1;
    }
    else{
        int temp = top;
        length--;
        top = stackArr[length-1];
        return temp;
    }
}

int Stack::getTop(){
    if (top != -1){
        return top;
    }
    return -1;
}

int Stack::getSize(){
    return size;
}

void Stack::printStack(){
    for(int i=0;i<length;i++){
        cout<<stackArr[i]<<",";
    }
    cout<<endl;
}