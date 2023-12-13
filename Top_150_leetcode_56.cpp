#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    // If both trees are empty, they are identical
    if (p == nullptr && q == nullptr) {
        return true;
    }
    
    // If one tree is empty but the other is not, they are not identical
    if (p == nullptr || q == nullptr) {
        return false;
    }
    
    // If values of the current nodes are different, trees are not identical
    if (p->val != q->val) {
        return false;
    }
    
    // Recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    // Example usage
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = isSameTree(p, q);
    if (result) {
        std::cout << "The trees are identical." << std::endl;
    } else {
        std::cout << "The trees are not identical." << std::endl;
    }

    // Clean up memory (free allocated nodes)
    delete q->right;
    delete q->left;
    delete q;
    delete p->right;
    delete p->left;
    delete p;

    return 0;
}
