#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (!head || !head->next) {
        return false; // If the list is empty or has only one node, there can't be a cycle.
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != slow) {
        if (!fast || !fast->next) {
            return false; // If fast or its next is nullptr, it's the end of the list.
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return true; // If fast and slow pointers meet, there's a cycle.
}

int main() {
    // Create a linked list with a cycle for testing
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle here

    bool hasCycleResult = hasCycle(head);
    if (hasCycleResult) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list doesn't have a cycle." << endl;
    }

    // Clean up memory (free the allocated nodes)
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
