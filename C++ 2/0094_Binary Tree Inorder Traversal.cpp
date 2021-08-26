class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        convertToInorder(root, inorder);
        
        return inorder;
    }
    
    void convertToInorder(TreeNode* node, vector<int>& outArray) {
        if (node == nullptr) {
            return;
        }
        
        convertToInorder(node->left, outArray);
        outArray.push_back(node->val);
        convertToInorder(node->right, outArray);
    }
};