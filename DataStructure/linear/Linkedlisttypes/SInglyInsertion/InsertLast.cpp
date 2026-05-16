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

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->next = third;

    // Create new node
    Node* newNode = new Node(40);

    // Traverse to last node
    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    // Insert at end
    temp->next = newNode;

    // Traversal
    temp = head;

    while(temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}