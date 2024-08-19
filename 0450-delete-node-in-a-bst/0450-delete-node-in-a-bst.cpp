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
    TreeNode* deleteNode(TreeNode* root, int key) {
     if (root == nullptr) {
            return nullptr;
        }
        
        // If the key to be deleted is smaller than the root's key, go to the left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        // If the key to be deleted is greater than the root's key, go to the right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // If the key is the same as the root's key, this is the node to be deleted
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            // Node with two children: get the inorder successor (smallest in the right subtree)
            TreeNode* temp = minValueNode(root->right);
            
            // Copy the inorder successor's content to this node
            root->val = temp->val;
            
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
        
        return root;
    }
    
    // Helper function to find the minimum value node in a given tree
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        
        // Loop to find the leftmost leaf
        while (current && current->left != nullptr) {
            current = current->left;
        }
        
        return current;
    }
};