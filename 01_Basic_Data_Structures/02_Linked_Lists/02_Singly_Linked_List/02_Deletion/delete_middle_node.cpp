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

    // Delete middle node (15)
    Node* temp = head;

    while (temp->next->data != 15) {
        temp = temp->next;
    }

    Node* tempDelete = temp->next;

    temp->next = temp->next->next;

    delete tempDelete;

    // Traversal
    temp = head;

    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}