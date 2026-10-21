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