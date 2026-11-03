#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        return dummy.next;
    }
};

static ListNode* buildList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* tail = dummy;
    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

static void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << '\n';
}

static void deleteList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    // Structure: {{List1}, {List2}} pairs
    std::vector<std::pair<std::vector<int>, std::vector<int>>> testCases = {
        {{2, 4, 3}, {5, 6, 4}},  // 342 + 465 = 807  -> Expected: 7 -> 0 -> 8
        {{0}, {0}},              // 0 + 0 = 0        -> Expected: 0
        {{9, 9, 9}, {1}},        // 999 + 1 = 1000   -> Expected: 0 -> 0 -> 0 -> 1
        {{2, 4}, {5, 6, 4}}      // 42 + 465 = 507   -> Expected: 7 -> 0 -> 5
    };

    for (const auto& pair : testCases) {
        ListNode* l1 = buildList(pair.first);
        ListNode* l2 = buildList(pair.second);
        
        Solution solution;
        ListNode* result = solution.addTwoNumbers(l1, l2);
        
        printList(result);
        
        deleteList(l1);
        deleteList(l2);
        deleteList(result);
    }

    return 0;
}
