#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // The depth of the tree is the maximum depth of its left and right subtrees + 1 (for the root node)
        return 1 + std::max(leftDepth, rightDepth);
    }
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int depth = maxDepth(root);
    std::cout << "Maximum depth of the binary tree is: " << depth << std::endl;

    // Clean up memory (free allocated nodes)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
