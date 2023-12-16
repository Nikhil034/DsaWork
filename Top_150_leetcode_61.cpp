#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void flatten(TreeNode* root) {
    if (!root) return;

    // Store the right subtree
    TreeNode* rightSubtree = root->right;

    // Flatten the left subtree
    flatten(root->left);

    // Move the flattened left subtree to the right
    root->right = root->left;
    root->left = nullptr;

    // Move to the end of the new right subtree
    while (root->right) {
        root = root->right;
    }

    // Attach the right subtree after the flattened left subtree
    root->right = rightSubtree;

    // Flatten the right subtree
    flatten(rightSubtree);
}

void printList(TreeNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->right;
    }
    std::cout << std::endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    std::cout << "Original Tree:" << std::endl;
    /*
              1
             / \
            2   5
           / \    \
          3   4    6
    */

    flatten(root);

    std::cout << "Flattened List:" << std::endl;
    printList(root);
    
    return 0;
}
