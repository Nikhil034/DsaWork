#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i; // Mapping elements to their indices in inorder array
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int, int>& inorderMap) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr; // Base case: No elements to construct tree
        }

        int rootValue = preorder[preStart]; // Root value from preorder
        TreeNode* root = new TreeNode(rootValue);

        int rootIndexInInorder = inorderMap[rootValue]; // Index of root in inorder

        int leftSubtreeSize = rootIndexInInorder - inStart; // Size of left subtree

        root->left = build(preorder, preStart + 1, preStart + leftSubtreeSize,
                           inorder, inStart, rootIndexInInorder - 1, inorderMap);
        root->right = build(preorder, preStart + leftSubtreeSize + 1, preEnd,
                            inorder, rootIndexInInorder + 1, inEnd, inorderMap);
  
        return root;
    }
};

// Function to print inorder traversal of the constructed tree
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
