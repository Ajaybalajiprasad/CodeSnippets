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

    void insert(int data){
        Node* newNode = new Node(data);
        if(head !=  nullptr){
            head->prev = newNode;  
        }
        newNode ->next=head;
        head = newNode;
    }

    void pairSum(int x){
        Node* left = head;
        Node* right = head;
        while(right->next != nullptr){
            right = right->next;
        }

        bool found = false;
        while(left->data < right->data){
            if(left->data+right->data == x){
                cout<<"{"<<left->data<<","<<right->data<<"}"<<endl;
                found = true;
                left=left->next;
                right=right->prev;
            }else if(left->data+right->data > x){
                right = right->prev;
            }else{
                left=left->next;
            }
        }
        if(found == false){
            cout<<"No pair found with given sum"<<endl;
        }
    }
};

int main(){
    DoublyLinkedList dll;

    dll.insert(6);
    dll.insert(5);
    dll.insert(4);
    dll.insert(2);
    dll.insert(1);

    int x = 7;

    dll.pairSum(x);

    return 0;
    
}
