#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<double> averageOfLevels(TreeNode* root) {
    std::vector<double> averages;
    if (root == nullptr) return averages;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        double sum = 0.0;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        averages.push_back(sum / size);
    }

    return averages;
}

// Example usage
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::vector<double> result = averageOfLevels(root);

    std::cout << "Average values of nodes at each level: ";
    for (double avg : result) {
        std::cout << avg << " ";
    }
    std::cout << std::endl;

    return 0;
}
