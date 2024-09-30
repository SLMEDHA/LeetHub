/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "null";
        
        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                ss << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null ";
            }
        }
        
        return ss.str();
    }

    // Deserialize a string back to a binary tree.
    TreeNode* deserialize(const string& data) {
        if (data == "null") return nullptr;
        
        stringstream ss(data);
        string val;
        ss >> val;
        
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            // Deserialize the left child
            if (ss >> val) {
                if (val != "null") {
                    TreeNode* leftChild = new TreeNode(stoi(val));
                    node->left = leftChild;
                    q.push(leftChild);
                }
            }
            
            // Deserialize the right child
            if (ss >> val) {
                if (val != "null") {
                    TreeNode* rightChild = new TreeNode(stoi(val));
                    node->right = rightChild;
                    q.push(rightChild);
                }
            }
        }
        
        return root;
    }
};