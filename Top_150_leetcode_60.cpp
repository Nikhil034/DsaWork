#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                Node* current = q.front();
                q.pop();

                if (i < levelSize - 1) {
                    current->next = q.front();
                }

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }

        return root;
    }
};

// Utility function to print the next pointers (for visualization)
void printNextPointers(Node* root) {
    while (root) {
        Node* temp = root;
        while (temp) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        root = root->left;
    }
}

int main() {
    // Example tree creation
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    Solution sol;
    Node* connectedTree = sol.connect(root);

    cout << "Next pointers of each node in the tree:" << endl;
    printNextPointers(connectedTree);

    return 0;
}
