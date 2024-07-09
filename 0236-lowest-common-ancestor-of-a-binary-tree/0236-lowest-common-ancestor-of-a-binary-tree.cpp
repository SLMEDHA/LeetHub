/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        // Recurse on left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right are non-null, root is the LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }
        
        // Otherwise, return the non-null child
        if (left != nullptr) {
            return left;
        } else {
            return right;
        }
    }
};