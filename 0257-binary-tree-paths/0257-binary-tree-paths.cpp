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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths; // To store all the root-to-leaf paths
        if (root != nullptr) {
            dfs(root, "", paths); // Start the DFS traversal from the root
        }
        return paths; // Return the collected paths
    }
    
private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        if (node == nullptr) {
            return; // If the current node is null, return
        }
        
        path += to_string(node->val); // Append the current node's value to the path
        
        if (node->left == nullptr && node->right == nullptr) {
            // If the current node is a leaf node
            paths.push_back(path); // Add the complete path to the paths vector
        } else {
            // If the current node is not a leaf node
            path += "->"; // Append "->" to indicate the path continuation
            if (node->left != nullptr) {
                dfs(node->left, path, paths); // Recursively call DFS on the left subtree
            }
            if (node->right != nullptr) {
                dfs(node->right, path, paths); // Recursively call DFS on the right subtree
            }
        }
    }
};