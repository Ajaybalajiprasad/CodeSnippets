```
#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {};
};

class DoublyLinkedList{
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {};

    Node* insert(int data){
        Node* newNode = new Node(data);
        if(head==nullptr){
            head = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return head;
    }
};

void display(Node* head){
    Node* cur = head;
    while(cur!=nullptr){
        cout<<cur->data<<"->";
        cur = cur->next;
    }
}
int main(){
    DoublyLinkedList dil;

    dil.insert(6);
    dil.insert(10);
    dil.insert(15);
    dil.insert(3);

    cout<<"the doubly linked list is "<<endl;
    display(dil.head);
    cout<<endl;
    return 0;
}
```
