#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int newData) : data(newData), next(NULL){};
};

class LinkedList{
public:
    Node* head;

    LinkedList() : head(nullptr) {};

    void insert(int data){
        Node* newNode = new Node(data);
        if(head==nullptr){
            head = newNode;
        }else{
            Node* cur = head;
            while(cur->next != NULL){
                cur = cur->next;
            }
            cur->next = newNode;
        }
    }

    bool Cycle(){
        if(head==nullptr || head->next == nullptr){
            return false;
        }

        Node* fast = head;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;

            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};
int main(){
    LinkedList ll;

    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);

    //creating a cycle
    ll.head->next->next->next->next->next/*6*/ = ll.head->next->next->next;//4
    //above the 6th Node points to 4 th Node



    if(ll.Cycle()){
        cout<<"The Linked has a cycle"<<endl;
    }else{
        cout<<"The Linked does not have a cycle"<<endl;
    }

    return 0;
}




