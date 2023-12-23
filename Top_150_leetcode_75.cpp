#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }

    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

// Function to print the tree nodes (for testing purposes)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9}; // Sample sorted array
    TreeNode* root = sortedArrayToBST(nums);

    cout << "Constructed Balanced BST: ";
    printTree(root);

    return 0;
}
