#include <iostream>
#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (root == nullptr) {
        return true;
    }

    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }

    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}

// Example usage
int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isValidBST(root)) {
        std::cout << "The binary tree is a valid BST." << std::endl;
    } else {
        std::cout << "The binary tree is not a valid BST." << std::endl;
    }

    // Free allocated memory
    // Code for tree deletion is omitted for simplicity
    return 0;
}
