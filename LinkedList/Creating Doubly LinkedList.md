```
#include<iostream>
using namespace std;


class Node {
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
            Node* cur = head;
            while(cur->next!=nullptr){
                cur = cur->next;
            }
            cur->next = newNode;
            newNode->prev = cur;
        }
        return head;
    }

    void display(){
    Node* cur = head;
    while(cur!=nullptr){
        if(cur->next!=nullptr){
            cout<<cur->data<<"->";
        }else{
            cout<<cur->data;
        }
        cur = cur->next;

    }
}
};


int main(){
    DoublyLinkedList dil;
    
    dil.insert(6);
    dil.insert(10);
    dil.insert(15);
    dil.insert(3);

    cout<<"the doubly linked list is "<<endl;
    dil.display();

    return 0;
}
