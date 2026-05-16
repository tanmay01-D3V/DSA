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

    // Original list
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->next = third;

    // Insert at beginning
    Node* newNode = new Node(5);

    newNode->next = head;
    head = newNode;

    // Traversal
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}