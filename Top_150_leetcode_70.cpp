#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root, int& prev, int& minDiff) {
    if (root == nullptr) return;

    inorderTraversal(root->left, prev, minDiff);

    if (prev != -1) {
        minDiff = (minDiff == -1) ? root->val - prev : min(minDiff, root->val - prev);
    }
    prev = root->val;

    inorderTraversal(root->right, prev, minDiff);
}

int getMinimumDifference(TreeNode* root) {
    int minDiff = -1; // Initialize with an invalid value
    int prev = -1;    // To store the previously visited node's value

    inorderTraversal(root, prev, minDiff);

    return minDiff;
}

// Utility function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* temp = new TreeNode(val);
    return temp;
}

int main() {
    // Create a sample binary search tree
    TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int minDiff = getMinimumDifference(root);
    cout << "Minimum Absolute Difference: " << minDiff << endl;

    return 0;
}
