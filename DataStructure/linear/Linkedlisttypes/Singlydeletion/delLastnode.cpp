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
    Node* head = new Node(10);
    Node* second = new Node(20);

    // Linking nodes
    head->next = second;

    // Delete first node
    Node* tempDelete = head;
    head = head->next;
    delete tempDelete;

    // Traversal
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}