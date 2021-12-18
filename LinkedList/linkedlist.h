#include "node.h"
#include <iostream>

using namespace std;

class LinkedList{
public:
    LinkedList();
    void Insert(int data);
    void Delete(int data);
    void Length();
    void Items();

private:
    Node* head;
    Node* tail;
    int length{};
};

LinkedList::LinkedList(){
    head = NULL;
    tail= NULL;
}

void LinkedList::Insert(int data){
    if(head == NULL){
        Node* temp = new Node();
        temp->data = data;
        temp->next = NULL;
        head = temp;
        tail=temp;
        length++;
    }
    else{
        Node* temp = new Node();
        temp->data = data;
        temp->next = NULL;
        tail->next = temp;
        tail=temp;
        length++;
    }
}

void LinkedList::Delete(int data){
    if(head->data == data){
        Node* current = head;
        head = head->next;
        current->next  = NULL;
        delete current;
        length--;
    }
    else{
        Node* current = head;
        Node* prev = NULL;
        while(current->data != data){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        length--;
        delete current;
    }
}

void LinkedList::Length(){
    cout<<"The length of linkedlist is: "<<length<<endl;
}

void LinkedList::Items(){
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<"->";
        current= current->next;
    }
    cout<<endl;
}