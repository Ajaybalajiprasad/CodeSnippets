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

    void deleteAtBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
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

    sll.deleteAtBeginning(); // List is empty. Nothing to delete.

    sll.insertAtBeginning(20);
    sll.insertAtBeginning(15);
    sll.insertAtBeginning(10);
    sll.insertAtBeginning(5);

    std::cout << "Singly Linked List before deletion:" << std::endl;
    sll.display();

    sll.deleteAtBeginning(); // Delete node at the beginning

    std::cout << "Singly Linked List after deletion:" << std::endl;
    sll.display();

    return 0;
}
```
