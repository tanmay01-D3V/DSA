#include <iostream>
#include <stack>

// Definition for a Multi-level Doubly Linked List Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        // Use a stack to mimic the pre-order traversal order (Node -> Child -> Next)
        std::stack<Node*> st;
        st.push(head);
        
        Node* prevNode = nullptr;

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();

            // If there's a previous node, hook up the bidirectional connections
            if (prevNode) {
                prevNode->next = curr;
                curr->prev = prevNode;
            }

            // Push next first so it gets processed AFTER the child sublist (LIFO order)
            if (curr->next) {
                st.push(curr->next);
            }
            
            // Push child second so it gets processed immediately next
            if (curr->child) {
                st.push(curr->child);
                // Crucial step: Once integrated, clear the child pointer
                curr->child = nullptr;
            }

            // Move our tracking pointer forward
            prevNode = curr;
        }

        return head;
    }
};

// Helper function to print the flattened list forward and backward to verify pointers
void printList(Node* head) {
    Node* curr = head;
    Node* tail = nullptr;
    
    std::cout << "Forward:  ";
    while (curr) {
        std::cout << curr->val << " ";
        if (!curr->next) tail = curr;
        curr = curr->next;
    }
    std::cout << "\nBackward: ";
    while (tail) {
        std::cout << tail->val << " ";
        tail = tail->prev;
    }
    std::cout << "\n";
}

int main() {
    // Constructing a sample multilevel list:
    // 1 <-> 2 <-> 3
    //       |
    //       4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(3); head->next->next->prev = head->next;
    
    Node* childHead = new Node(4);
    childHead->next = new Node(5); childHead->next->prev = childHead;
    
    // Attach child sublist to Node 2
    head->next->child = childHead;

    Solution solver;
    Node* flattenedHead = solver.flatten(head);

    printList(flattenedHead); // Expected order: 1 2 4 5 3

    return 0;
}
