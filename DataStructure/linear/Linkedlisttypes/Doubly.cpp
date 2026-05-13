#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;  // ✅ extra pointer for doubly

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main() {
    // Creating nodes
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);

    // Linking nodes (forward)
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Linking nodes (backward)  ✅
    node1->prev = NULL;
    node2->prev = node1;
    node3->prev = node2;

    // Forward Traversal
    cout << "Forward:  ";
    Node* temp = node1;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << " <-> NULL\n";

    // Backward Traversal  ✅
    cout << "Backward: ";
    temp = node3;  // start from last node
    while (temp != NULL) {
        cout << temp->data;
        if (temp->prev != NULL) cout << " <-> ";
        temp = temp->prev;
    }
    cout << " <-> NULL\n";

    return 0;
}