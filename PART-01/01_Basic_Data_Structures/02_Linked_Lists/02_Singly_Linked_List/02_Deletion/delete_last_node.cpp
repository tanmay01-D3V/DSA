#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {

    // Creating nodes
    Node* head = new Node(5);
    Node* second = new Node(10);
    Node* third = new Node(15);
    Node* fourth = new Node(20);
    Node* fifth = new Node(25);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Delete last node
    Node* temp = head;

    // Move to second-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Delete last node
    delete temp->next;

    // Make second-last node point to NULL
    temp->next = NULL;

    // Traversal
    temp = head;

    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}