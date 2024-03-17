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

    Node* getMiddle() {
        if (head == nullptr) {
            return nullptr; // Empty list, no middle element
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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

    Node* middle = sll.getMiddle();
    
    if (middle != nullptr) {
        std::cout << "Middle Element: " << middle->data << std::endl;
    } else {
        std::cout << "The list is empty, no middle element." << std::endl;
    }

    return 0;
}

```
