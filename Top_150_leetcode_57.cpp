#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to invert a binary tree
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // Swap left and right subtrees recursively
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    
    return root;
}

// Function to print the tree (for testing purposes)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    std::cout << "Original Tree: ";
    printTree(root);
    std::cout << std::endl;
    
    // Invert the tree
    root = invertTree(root);
    
    std::cout << "Inverted Tree: ";
    printTree(root);
    std::cout << std::endl;
    
    // Clean up memory (deallocating nodes)
    // Clean up code is omitted for brevity in this example

    return 0;
}
