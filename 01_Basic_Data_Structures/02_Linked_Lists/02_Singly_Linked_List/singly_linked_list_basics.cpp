#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    // Creating nodes
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);

    // Linking nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;  // ✅ last node points to NULL

    // Traversal
    Node* temp = node1;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";  // ✅ correct arrow
        temp = temp->next;
    }
    cout << " -> NULL\n";
    return 0;
}