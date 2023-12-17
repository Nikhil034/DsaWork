#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumNumbers(TreeNode* root) {
    return sumNumbersHelper(root, 0);
}

int sumNumbersHelper(TreeNode* root, int currentSum) {
    if (root == nullptr) {
        return 0;
    }
    
    // Calculate the sum considering the current node's value
    currentSum = currentSum * 10 + root->val;
    
    // If it's a leaf node, return the current sum
    if (root->left == nullptr && root->right == nullptr) {
        return currentSum;
    }
    
    // Recursively calculate the sum for left and right subtrees
    int leftSum = sumNumbersHelper(root->left, currentSum);
    int rightSum = sumNumbersHelper(root->right, currentSum);
    
    // Return the sum of both subtrees
    return leftSum + rightSum;
}

// Example usage
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    int result = sumNumbers(root);
    std::cout << "Total sum of root-to-leaf numbers: " << result << std::endl;
    
    return 0;
}
