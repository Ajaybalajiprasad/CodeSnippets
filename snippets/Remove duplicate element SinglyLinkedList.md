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

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void removeDuplicates() {
        Node* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }
};

int main() {
    SinglyLinkedList myList;

    myList.insert(1);
    myList.insert(2);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);
    myList.insert(4);
    myList.insert(5);

    std::cout << "Original linked list: ";
    myList.display();

    myList.removeDuplicates();

    std::cout << "Linked list after removing duplicates: ";
    myList.display();

    return 0;
}
```
