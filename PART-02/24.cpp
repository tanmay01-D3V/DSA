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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
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
    std::vector<std::vector<int>> testCases = {{1, 2, 3, 4}, {1, 2, 3, 4, 5}, {1, 2}, {1}};

    for (const auto& values : testCases) {
        ListNode* head = buildList(values);
        Solution solution;
        head = solution.swapPairs(head);
        printList(head);
        deleteList(head);
    }

    return 0;
}
