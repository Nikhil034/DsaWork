#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Merge two sorted lists
ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }

    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Split the list into two halves
ListNode* getMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) {
        prev->next = nullptr;
    }

    return slow;
}

// Merge Sort for linked list
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode* mid = getMiddle(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);

    return merge(left, right);
}

// Function to print the linked list (for testing purposes)
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    // Sort the linked list
    ListNode* sortedList = sortList(head);

    cout << "Sorted List: ";
    printList(sortedList);

    return 0;
}
