class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        maxGain(root, globalMax);
        return globalMax;
    }

private:
    // Helper function to calculate the maximum gain from each node
    int maxGain(TreeNode* node, int& globalMax) {
        if (node == nullptr) {
            return 0;
        }

        // Recursively compute the maximum path sum from the left and right subtrees
        // We only take the positive gains, because a negative gain would reduce the total sum
        int leftGain = std::max(maxGain(node->left, globalMax), 0);
        int rightGain = std::max(maxGain(node->right, globalMax), 0);

        // Compute the path sum that includes the current node as the root and both children
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the global maximum if the current path sum is larger
        globalMax = std::max(globalMax, currentPathSum);

        // Return the maximum gain that can be obtained by including the current node in the path
        return node->val + std::max(leftGain, rightGain);
    }
};
