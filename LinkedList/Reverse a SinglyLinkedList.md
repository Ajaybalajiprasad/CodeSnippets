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

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }
};

int main() {
    SinglyLinkedList sll;

    // Inserting nodes manually for demonstration
    sll.head = new Node(5);
    sll.head->next = new Node(10);
    sll.head->next->next = new Node(15);
    sll.head->next->next->next = new Node(20);

    std::cout << "Original Singly Linked List:" << std::endl;
    sll.display();

    sll.reverse();

    std::cout << "Reversed Singly Linked List:" << std::endl;
    sll.display();

    return 0;
}

```
