#include<bits/stdc++.h>
using namespace std;
 
class Node{
public:
    int data;
    Node* next;

    Node(int val) : data(val),next(nullptr) {};
};

class LinkedList{
public:
    Node* mergeList(Node* l1, Node* l2){
        Node* temp = new Node(-1);
        Node* cur = temp;
        while(l1!=NULL && l2!=NULL){
            if(l1->data <= l2->data){
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if(l1!=NULL){
            cur->next = l1;
        }else{
            cur->next = l2;
        }
        return temp->next;
    }
};

void Print(Node* head){
    Node* cur = head;
    while(cur!=NULL){
        cout<<cur->data<<"->";
        cur = cur->next;
    }
    cout<<endl;
}

int main(){
    LinkedList sl;

    Node* list1 = new Node(2);
    list1->next = new Node(5);
    list1->next->next = new Node(7);
    

    Node* list2 = new Node(3);
    list2->next = new Node(10);
    list2->next->next = new Node(15);


    Node* ans = sl.mergeList(list1,list2);

    cout<<"Linked list After merging"<<endl;
    Print(ans);
}

