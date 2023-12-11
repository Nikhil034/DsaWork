#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* current = head;

    while (current) {
        while (current->next && current->val == current->next->val) {
            current = current->next;
        }

        if (prev->next == current) {
            prev = prev->next;
        } else {
            prev->next = current->next;
        }

        current = current->next;
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
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    ListNode* distinctList = deleteDuplicates(head);

    std::cout << "Distinct List: ";
    printList(distinctList);

    return 0;
}
