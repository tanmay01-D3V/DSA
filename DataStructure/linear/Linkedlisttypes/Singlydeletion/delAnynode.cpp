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

// Display function
void display(Node* head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    // First node
    cout << "Enter value for node 1: ";
    cin >> value;

    Node* head = new Node(value);
    Node* temp = head;

    // Remaining nodes
    for(int i = 2; i <= n; i++) {

        cout << "Enter value for node " << i << ": ";
        cin >> value;

        Node* newNode = new Node(value);

        temp->next = newNode;
        temp = temp->next;
    }

    cout << "\nOriginal Linked List:\n";
    display(head);

    // Deletion
    int position;

    cout << "\nEnter position for deletion: ";
    cin >> position;

    // Delete first node
    if(position == 1) {

        Node* tempDelete = head;

        head = head->next;

        delete tempDelete;
    }
    else {

        temp = head;

        for(int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        Node* tempDelete = temp->next;

        temp->next = temp->next->next;

        delete tempDelete;
    }

    cout << "\nLinked List After Deletion:\n";
    display(head);

    return 0;
}