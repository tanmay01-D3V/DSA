#include <iostream>
#include <stdexcept>
using namespace std;

// ─────────────────────────────────────────────
//  Node structure
// ─────────────────────────────────────────────
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// ─────────────────────────────────────────────
//  Singly Linked List class
// ─────────────────────────────────────────────
class LinkedList {
private:
    Node* head;
    int size;

public:
    // Constructor
    LinkedList() : head(nullptr), size(0) {}

    // Destructor — frees all nodes
    ~LinkedList() {
        clear();
    }

    // ── Insertion ────────────────────────────

    // Insert at the beginning  O(1)
    void insertAtFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Insert at the end  O(n)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    // Insert at a given position (0-indexed)  O(n)
    void insertAtPosition(int val, int pos) {
        if (pos < 0 || pos > size)
            throw out_of_range("Position out of range");

        if (pos == 0) {
            insertAtFront(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    // ── Deletion ─────────────────────────────

    // Delete from the front  O(1)
    void deleteFromFront() {
        if (!head) throw underflow_error("List is empty");
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        size--;
    }

    // Delete from the end  O(n)
    void deleteFromEnd() {
        if (!head) throw underflow_error("List is empty");

        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next)
                temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        size--;
    }

    // Delete a node by value (first occurrence)  O(n)
    bool deleteByValue(int val) {
        if (!head) return false;

        if (head->data == val) {
            deleteFromFront();
            return true;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;

        if (!temp->next) return false;   // value not found

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        size--;
        return true;
    }

    // Delete at a given position (0-indexed)  O(n)
    void deleteAtPosition(int pos) {
        if (pos < 0 || pos >= size)
            throw out_of_range("Position out of range");

        if (pos == 0) {
            deleteFromFront();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        size--;
    }

    // ── Search ───────────────────────────────

    // Search by value; returns index or -1  O(n)
    int search(int val) const {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == val) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    // Get value at position  O(n)
    int getAt(int pos) const {
        if (pos < 0 || pos >= size)
            throw out_of_range("Position out of range");
        Node* temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        return temp->data;
    }

    // ── Update ───────────────────────────────

    // Update value at position  O(n)
    void updateAt(int pos, int newVal) {
        if (pos < 0 || pos >= size)
            throw out_of_range("Position out of range");
        Node* temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        temp->data = newVal;
    }

    // ── Utility ──────────────────────────────

    // Reverse the list in-place  O(n)
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Detect a cycle using Floyd's algorithm  O(n)
    bool hasCycle() const {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // Find the middle node  O(n)
    Node* findMiddle() const {
        if (!head) return nullptr;
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Remove duplicates from a sorted list  O(n)
    void removeDuplicates() {
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->data == temp->next->data) {
                Node* toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
                size--;
            } else {
                temp = temp->next;
            }
        }
    }

    // Sort the list (Bubble Sort)  O(n²)
    void sort() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp->next) {
                if (temp->data > temp->next->data) {
                    swap(temp->data, temp->next->data);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    // Clear the entire list  O(n)
    void clear() {
        while (head)
            deleteFromFront();
    }

    // Getters
    int getSize() const { return size; }
    bool isEmpty() const { return head == nullptr; }
    Node* getHead() const { return head; }

    // Display the list
    void display() const {
        if (!head) {
            cout << "[empty list]\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    // Print list details
    void printInfo() const {
        cout << "Size : " << size << "\n";
        cout << "List : ";
        display();
    }
};

// ─────────────────────────────────────────────
//  Doubly Linked List (bonus)
// ─────────────────────────────────────────────
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() { clear(); }

    void insertAtFront(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void deleteFromFront() {
        if (!head) throw underflow_error("List is empty");
        DNode* toDelete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete toDelete;
        size--;
    }

    void deleteFromEnd() {
        if (!tail) throw underflow_error("List is empty");
        DNode* toDelete = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete toDelete;
        size--;
    }

    void displayForward() const {
        DNode* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    void displayBackward() const {
        DNode* temp = tail;
        while (temp) {
            cout << temp->data;
            if (temp->prev) cout << " <-> ";
            temp = temp->prev;
        }
        cout << " -> NULL\n";
    }

    void clear() {
        while (head) deleteFromFront();
    }

    int getSize() const { return size; }
};

// ─────────────────────────────────────────────
//  Circular Linked List (bonus)
// ─────────────────────────────────────────────
class CircularLinkedList {
private:
    Node* tail;   // tail->next points back to head
    int size;

public:
    CircularLinkedList() : tail(nullptr), size(0) {}

    ~CircularLinkedList() { clear(); }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;   // points to itself
        } else {
            newNode->next = tail->next;  // new->next = head
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void deleteValue(int val) {
        if (!tail) return;
        Node* curr = tail->next;   // head
        Node* prev = tail;
        do {
            if (curr->data == val) {
                if (curr == tail && curr->next == tail) {
                    // only one node
                    delete curr;
                    tail = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == tail) tail = prev;
                    delete curr;
                }
                size--;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
    }

    void display() const {
        if (!tail) { cout << "[empty circular list]\n"; return; }
        Node* temp = tail->next;   // head
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to head)\n";
    }

    void clear() {
        if (!tail) return;
        Node* curr = tail->next;
        tail->next = nullptr;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        tail = nullptr;
        size = 0;
    }

    int getSize() const { return size; }
};

// ─────────────────────────────────────────────
//  Main — demonstration
// ─────────────────────────────────────────────
int main() {
    cout << "========================================\n";
    cout << "        SINGLY LINKED LIST DEMO\n";
    cout << "========================================\n";

    LinkedList list;

    // Insertions
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtFront(5);
    list.insertAtPosition(15, 2);   // insert 15 at index 2

    cout << "\n[After insertions]\n";
    list.printInfo();

    // Search
    cout << "\n[Search]\n";
    int idx = list.search(15);
    cout << "Index of 15: " << (idx != -1 ? to_string(idx) : "not found") << "\n";

    // Update
    list.updateAt(2, 99);
    cout << "\n[After updating index 2 to 99]\n";
    list.display();

    // Deletion
    list.deleteFromFront();
    list.deleteFromEnd();
    list.deleteByValue(99);

    cout << "\n[After 3 deletions]\n";
    list.display();

    // Reverse
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.reverse();
    cout << "\n[After reverse]\n";
    list.display();

    // Middle
    Node* mid = list.findMiddle();
    cout << "\nMiddle element: " << (mid ? to_string(mid->data) : "none") << "\n";

    // Sort
    list.insertAtFront(1);
    list.insertAtEnd(25);
    list.sort();
    cout << "\n[After sort]\n";
    list.display();

    // Cycle detection
    cout << "\nHas cycle? " << (list.hasCycle() ? "YES" : "NO") << "\n";

    cout << "\n========================================\n";
    cout << "        DOUBLY LINKED LIST DEMO\n";
    cout << "========================================\n";

    DoublyLinkedList dlist;
    dlist.insertAtEnd(1);
    dlist.insertAtEnd(2);
    dlist.insertAtEnd(3);
    dlist.insertAtFront(0);

    cout << "\nForward  : "; dlist.displayForward();
    cout << "Backward : "; dlist.displayBackward();

    dlist.deleteFromEnd();
    cout << "\n[After deleteFromEnd]\n";
    cout << "Forward  : "; dlist.displayForward();

    cout << "\n========================================\n";
    cout << "       CIRCULAR LINKED LIST DEMO\n";
    cout << "========================================\n";

    CircularLinkedList clist;
    clist.insert(10);
    clist.insert(20);
    clist.insert(30);
    clist.insert(40);

    cout << "\n"; clist.display();

    clist.deleteValue(20);
    cout << "[After deleting 20]\n";
    clist.display();

    cout << "\n========================================\n";
    cout << "              ALL DONE\n";
    cout << "========================================\n";

    return 0;
}