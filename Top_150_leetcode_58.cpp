#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to check if two subtrees are mirrors of each other
bool isMirror(TreeNode* leftSubtree, TreeNode* rightSubtree) {
    // If both subtrees are empty, they are mirrors
    if (leftSubtree == nullptr && rightSubtree == nullptr) {
        return true;
    }
    
    // If only one subtree is empty, they are not mirrors
    if (leftSubtree == nullptr || rightSubtree == nullptr) {
        return false;
    }
    
    // Check if values at the current nodes are equal
    // and the left subtree of the left node is mirrored with the right subtree of the right node
    // and the right subtree of the left node is mirrored with the left subtree of the right node
    return (leftSubtree->val == rightSubtree->val)
        && isMirror(leftSubtree->left, rightSubtree->right)
        && isMirror(leftSubtree->right, rightSubtree->left);
}

// Function to check if a binary tree is symmetric
bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true; // An empty tree is symmetric
    }
    
    return isMirror(root->left, root->right);
}

int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    // Check if the tree is symmetric
    if (isSymmetric(root)) {
        std::cout << "The binary tree is symmetric." << std::endl;
    } else {
        std::cout << "The binary tree is not symmetric." << std::endl;
    }
    
    // Clean up memory (deallocating nodes)
    // Clean up code is omitted for brevity in this example

    return 0;
}
