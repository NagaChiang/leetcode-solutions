class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        
        return buildTree(preorder, inorder, inorderIndexMap, 0, 0, preorder.size());
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderIndexMap, int preStart, int inStart, int length) {
        if (length <= 0) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (length == 1) {
            return root;
        }
        
        int inRootIndex = inorderIndexMap[preorder[preStart]] - inStart;
        root->left = buildTree(preorder, inorder, inorderIndexMap, preStart + 1, inStart, inRootIndex);
        root->right = buildTree(preorder, inorder, inorderIndexMap, preStart + inRootIndex + 1, inStart + inRootIndex + 1, length - inRootIndex - 1);
            
        return root;
    }
};