#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* curr = dummyHead;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    ListNode* result = dummyHead->next;
    delete dummyHead;
    return result;
}

// Function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create two linked lists representing numbers 243 and 564
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "First list: ";
    printList(l1);

    cout << "Second list: ";
    printList(l2);

    // Add the two numbers represented by the linked lists
    ListNode* sum = addTwoNumbers(l1, l2);

    cout << "Sum of the two numbers: ";
    printList(sum);

    // Clean up memory (free the allocated nodes)
    ListNode* current = l1;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    current = l2;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    current = sum;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
