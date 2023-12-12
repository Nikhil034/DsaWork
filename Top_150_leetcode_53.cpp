#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void display(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

Node* rotateKTimes(Node* head, int k) {
    if (head == nullptr || k == 0) {
        return head;
    }

    int length = 1;
    Node* current = head;
    while (current->next != nullptr) {
        length++;
        current = current->next;
    }

    k = k % length;
    if (k == 0) {
        return head;
    }

    int stepsToNewHead = length - k - 1;
    current->next = head;

    while (stepsToNewHead--) {
        head = head->next;
    }

    Node* newHead = head->next;
    head->next = nullptr;
    return newHead;
}

int main() {
    Node* head = nullptr;
    insert(head, 5);
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    std::cout << "Original List: ";
    display(head);

    int k = 2; // Rotate by 2 positions (change k to your desired value)
    head = rotateKTimes(head, k);

    std::cout << "List after rotating " << k << " times: ";
    display(head);

    return 0;
}
