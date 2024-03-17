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

    void insertAtPosition(int data, int position) {
        Node* newNode = new Node(data);
        if (position == 0 || head == nullptr) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < position - 1 && current->next != nullptr; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
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

    sll.insertAtPosition(5, 0);
    sll.insertAtPosition(10, 1);
    sll.insertAtPosition(15, 1);
    sll.insertAtPosition(20, 2);

    std::cout << "Singly Linked List after inserting at a position:" << std::endl;
    sll.display();

    return 0;
}
```
