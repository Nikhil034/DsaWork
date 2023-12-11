#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right || head == nullptr) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    // Move prev to the node just before the sublist to be reversed
    for (int i = 1; i < left; ++i) {
        if (prev == nullptr) return head;
        prev = prev->next;
    }

    ListNode *current = prev->next;
    ListNode *next_node = nullptr;
    ListNode *temp = nullptr;

    // Reverse the sublist from left to right
    for (int i = left; i < right; ++i) {
        if (current == nullptr) break;

        next_node = current->next;
        current->next = next_node->next;
        next_node->next = prev->next;
        prev->next = next_node;
    }

    return dummy.next;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    int left = 2;
    int right = 4;

    ListNode* reversed = reverseBetween(head, left, right);

    std::cout << "Reversed List from position " << left << " to " << right << ": ";
    printList(reversed);

    return 0;
}
