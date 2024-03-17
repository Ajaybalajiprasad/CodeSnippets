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

    void search(int key) {
        Node* current = head;
        while (current != nullptr && current->data != key) {
            current = current->next;
        }
        if (current != nullptr) {
            std::cout << key << " found in the linked list." << std::endl;
        } else {
            std::cout << key << " not found in the linked list." << std::endl;
        }
    }
};

int main() {
    SinglyLinkedList sll;

    // Inserting nodes manually for demonstration
    sll.head = new Node(5);
    sll.head->next = new Node(10);
    sll.head->next->next = new Node(15);
    sll.head->next->next->next = new Node(20);

    std::cout << "Singly Linked List:" << std::endl;
    sll.display();

    int searchKey = 10;
    sll.search(searchKey);

    return 0;
}
```
