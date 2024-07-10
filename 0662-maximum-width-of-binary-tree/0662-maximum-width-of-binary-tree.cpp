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
    int widthOfBinaryTree(TreeNode* root) {
        vector<unsigned long long> leftmosts;
        return dfs(root, 0, 1, leftmosts);
    }
    
private:
    int dfs(TreeNode* node, int depth, unsigned long long position, vector<unsigned long long>& leftmosts) {
        if (!node) return 0;
        
        if (depth >= leftmosts.size()) {
            leftmosts.push_back(position);
        }
        
        int currentWidth = position - leftmosts[depth] + 1;
        int leftWidth = dfs(node->left, depth + 1, position * 2, leftmosts);
        int rightWidth = dfs(node->right, depth + 1, position * 2 + 1, leftmosts);
        
        return max({currentWidth, leftWidth, rightWidth});
    }
};