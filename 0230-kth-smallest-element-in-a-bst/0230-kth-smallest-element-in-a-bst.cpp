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
    int kthSmallest(TreeNode* root, int k) {
      return inOrderTraversal(root, k);
    }
    
private:
    // Helper function to perform in-order traversal and find the k-th smallest element
    int inOrderTraversal(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* current = root;
        int count = 0;
        
        while (current != nullptr || !s.empty()) {
            // Reach the leftmost node
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            
            // Process the node
            current = s.top();
            s.pop();
            count++;
            
            // If this is the k-th node, return its value
            if (count == k) {
                return current->val;
            }
            
            // Move to the right subtree
            current = current->right;
        }
        
        // In case k is out of bounds (which should not happen as per the problem description)
        return -1;
    }
};