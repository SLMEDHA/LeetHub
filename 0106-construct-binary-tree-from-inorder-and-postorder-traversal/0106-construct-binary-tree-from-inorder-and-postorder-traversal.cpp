class Solution {
private:
    unordered_map<int, int> inorderMap;
    int postIndex;
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;
        
        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);
        
        int inorderIndex = inorderMap[rootValue];
        
        root->right = buildTreeHelper(inorder, postorder, inorderIndex + 1, right);
        root->left = buildTreeHelper(inorder, postorder, left, inorderIndex - 1);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }
};