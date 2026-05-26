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

    // Insertion
    int position, newValue;

    cout << "\nEnter position for insertion: ";
    cin >> position;

    cout << "Enter value to insert: ";
    cin >> newValue;

    Node* newNode = new Node(newValue);

    // Insert at beginning
    if(position == 1) {

        newNode->next = head;
        head = newNode;
    }
    else {

        temp = head;

        for(int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "\nLinked List After Insertion:\n";
    display(head);

    return 0;
}