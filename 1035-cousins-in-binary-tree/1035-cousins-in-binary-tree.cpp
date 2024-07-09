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
  int depth_x = 0, depth_y = 0;
    TreeNode* parent_x = nullptr;
    TreeNode* parent_y = nullptr;
    
    void dfs(TreeNode* node, int x, int y, int depth, TreeNode* parent) {
        if (node == nullptr) return;
        
        if (node->val == x) {
            depth_x = depth;
            parent_x = parent;
        } else if (node->val == y) {
            depth_y = depth;
            parent_y = parent;
        }
        
        dfs(node->left, x, y, depth + 1, node);
        dfs(node->right, x, y, depth + 1, node);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0, nullptr);
        return (depth_x == depth_y) && (parent_x != parent_y);
    }
};