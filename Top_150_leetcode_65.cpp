// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode* root) {
    if (!root) return 0;

    int depth = 0;
    TreeNode *left = root, *right = root;

    // Calculate the depth by traversing left until reaching the leaf
    while (right) {
        left = left->left;
        right = right->right;
        depth++;
    }

    // If it's a full tree, the number of nodes = 2^depth - 1
    if (!left) return (1 << depth) - 1;

    // Perform a binary search on the last level to find the rightmost node
    int leftNode = 0, rightNode = (1 << depth) - 1;
    while (leftNode <= rightNode) {
        int mid = leftNode + (rightNode - leftNode) / 2;
        if (exists(root, mid, depth))
            leftNode = mid + 1;
        else
            rightNode = mid - 1;
    }

    return (1 << depth) - 1 + leftNode;
}

// Helper function to check if a node exists at the given index in the last level
bool exists(TreeNode* node, int idx, int depth) {
    int left = 0, right = (1 << depth) - 1;
    for (int d = 0; d < depth; ++d) {
        int mid = left + (right - left) / 2;
        if (idx <= mid) {
            node = node->left;
            right = mid;
        } else {
            node = node->right;
            left = mid + 1;
        }
    }
    return node != nullptr;
}
