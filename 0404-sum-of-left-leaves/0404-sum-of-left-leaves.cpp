/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
            return dfs(root, false);
    }
    
private:
    int dfs(TreeNode* node, bool isLeft) {
        if (node == nullptr) {
            return 0;
        }
        
        // Check if it's a leaf node and if it's a left child
        if (node->left == nullptr && node->right == nullptr) {
            if (isLeft) {
                return node->val;
            } else {
                return 0;
            }
        }
        
        // Recursively call dfs for left and right children
        int leftSum = dfs(node->left, true);
        int rightSum = dfs(node->right, false);
        
        return leftSum + rightSum;
    }
};