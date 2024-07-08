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
    int diameterOfBinaryTree(TreeNode* root) {
     int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    
private:
    int height(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }
        
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        
        // Update the diameter if the current path is longer
        diameter = max(diameter, leftHeight + rightHeight);
        
        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }
};