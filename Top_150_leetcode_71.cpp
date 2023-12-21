#include <iostream>
#include <stack>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> nodes;
    TreeNode* current = root;
    int count = 0;
    int kthSmallest = -1;

    while (current != nullptr || !nodes.empty()) {
        while (current != nullptr) {
            nodes.push(current);
            current = current->left;
        }

        current = nodes.top();
        nodes.pop();
        count++;

        if (count == k) {
            kthSmallest = current->val;
            break;
        }

        current = current->right;
    }

    return kthSmallest;
}

// Example usage
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 2;
    std::cout << "The " << k << "th smallest element is: " << kthSmallest(root, k) << std::endl;

    // Free allocated memory
    // Code for tree deletion is omitted for simplicity
    return 0;
}
