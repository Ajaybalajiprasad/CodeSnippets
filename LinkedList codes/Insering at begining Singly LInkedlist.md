```
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    SinglyLinkedList sll;

    sll.insertAtBeginning(20);
    sll.insertAtBeginning(15);
    sll.insertAtBeginning(10);
    sll.insertAtBeginning(5);

    std::cout << "Singly Linked List after inserting at the beginning:" << std::endl;
    sll.display();

    return 0;
}
```
