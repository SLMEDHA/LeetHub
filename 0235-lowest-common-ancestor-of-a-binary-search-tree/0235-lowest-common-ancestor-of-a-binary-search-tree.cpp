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
     while (root != nullptr) {
            // If both p and q are smaller than root, LCA must be in the left subtree
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // If both p and q are greater than root, LCA must be in the right subtree
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // Otherwise, root is the LCA
            else {
                return root;
            }
        }
        return nullptr; // This line should never be reached for valid inputs
    }
};