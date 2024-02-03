#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode *dummy = new ListNode(0); // Dummy node to simplify insertion
    dummy->next = head;

    ListNode *current = head->next;
    ListNode *prev = head;

    while (current) {
        if (current->val < prev->val) {
            ListNode *temp = dummy;

            // Find the correct position to insert the current node
            while (temp->next && temp->next->val < current->val) {
                temp = temp->next;
            }

            // Insert the current node
            prev->next = current->next;
            current->next = temp->next;
            temp->next = current;

            // Move to the next unsorted node
            current = prev->next;
        } else {
            // Move to the next unsorted node
            current = current->next;
            prev = prev->next;
        }
    }

    ListNode *result = dummy->next;
    delete dummy;

    return result;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage:
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    std::cout << "Original list: ";
    printList(head);

    head = insertionSortList(head);

    std::cout << "Sorted list: ";
    printList(head);

    return 0;
}
