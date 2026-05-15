#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

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

    // Forward links
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;  // ✅ last points back to first (circular)

    // Backward links
    node1->prev = node3;  // ✅ first points back to last (circular)
    node2->prev = node1;
    node3->prev = node2;

    // Forward Traversal
    cout << "Forward:  ";
    Node* temp = node1;
    do {
        cout << temp->data;
        if (temp->next != node1) cout << " <-> ";
        temp = temp->next;
    } while (temp != node1);  // ✅ stop when we reach head again
    cout << " <-> (back to head)\n";

    // Backward Traversal
    cout << "Backward: ";
    temp = node3;  // start from last node
    do {
        cout << temp->data;
        if (temp->prev != node3) cout << " <-> ";
        temp = temp->prev;
    } while (temp != node3);  // ✅ stop when we reach last again
    cout << " <-> (back to tail)\n";

    return 0;
}