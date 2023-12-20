#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            int index = (leftToRight) ? i : (size - 1 - i);
            level[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        leftToRight = !leftToRight;
        result.push_back(level);
    }

    return result;
}

// Utility function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* temp = new TreeNode(val);
    return temp;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    vector<vector<int>> zigzagOrder = zigzagLevelOrder(root);

    // Display the zigzag level order traversal
    cout << "Zigzag Level Order Traversal:" << endl;
    for (const auto& level : zigzagOrder) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
