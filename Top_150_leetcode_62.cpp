#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    // Check if it's a leaf node and if the sum matches the target
    if (!root->left && !root->right && root->val == targetSum) {
        return true;
    }

    // Recursively check for left and right subtrees
    bool leftPath = hasPathSum(root->left, targetSum - root->val);
    bool rightPath = hasPathSum(root->right, targetSum - root->val);

    return leftPath || rightPath;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    /*
             5
            / \
           4   8
          /   / \
         11  13  4
        / \      \
       7   2      1
    */

    bool hasPath = hasPathSum(root, targetSum);

    if (hasPath) {
        std::cout << "There exists a root-to-leaf path with sum " << targetSum << std::endl;
    } else {
        std::cout << "No root-to-leaf path with sum " << targetSum << " found" << std::endl;
    }

    return 0;
}
