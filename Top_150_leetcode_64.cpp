#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN; // Initialize the maximum path sum
    
    calculateMaxPathSum(root, maxSum);
    
    return maxSum;
}

int calculateMaxPathSum(TreeNode* root, int &maxSum) {
    if (root == nullptr) {
        return 0;
    }
    
    // Calculate the maximum path sum for left and right subtrees
    int leftSum = std::max(0, calculateMaxPathSum(root->left, maxSum));
    int rightSum = std::max(0, calculateMaxPathSum(root->right, maxSum));
    
    // Update the global maximum sum considering the current node's value
    maxSum = std::max(maxSum, leftSum + rightSum + root->val);
    
    // Return the maximum path sum achievable from the current node
    return std::max(leftSum, rightSum) + root->val;
}

// Example usage
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    
    int result = maxPathSum(root);
    std::cout << "Maximum path sum: " << result << std::endl;
    
    return 0;
}
