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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;  // Both are null
        if (!a || !b) return false; // One is null and the other is not
        
        // Compare current nodes and recursively check left and right subtrees
        return (a->val == b->val) && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }
    
    // Main function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;  // An empty tree is always a subtree
        if (!root) return false;    // If the main tree is empty, subRoot can't be a subtree
        
        // Check if the current trees match or recursively check in the left or right subtree
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};