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

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 0; current != nullptr && i < position - 1; ++i) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) {
            std::cout << "Invalid position. Cannot delete." << std::endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
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

    sll.insertAtEnd(5);
    sll.insertAtEnd(10);
    sll.insertAtEnd(15);
    sll.insertAtEnd(20);

    std::cout << "Singly Linked List before deletion:" << std::endl;
    sll.display();

    sll.deleteAtPosition(2); // Delete node at position 2

    std::cout << "Singly Linked List after deletion:" << std::endl;
    sll.display();

    return 0;
}

```
