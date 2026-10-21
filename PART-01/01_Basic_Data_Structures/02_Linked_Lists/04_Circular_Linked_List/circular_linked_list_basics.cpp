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

    // Linking nodes (circular)
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;  // circular

    // Traversal — stop when we reach head again ✅
    Node* temp = node1;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != node1);  // ✅ stop at head
    cout << "(back to head)\n";
    return 0;
}