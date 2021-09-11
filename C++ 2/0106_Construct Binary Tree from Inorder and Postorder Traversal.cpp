class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        
        return buildTree(inorder, postorder, inorderIndexMap, postorder.size() - 1, 0, inorder.size());
    }
    
private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inorderIndexMap, int postRight, int inLeft, int treeSize) {
        if (treeSize == 0) {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(postorder[postRight]);
        
        int inRootOffset = inorderIndexMap[postorder[postRight]] - inLeft;
        node->left = buildTree(inorder, postorder, inorderIndexMap, postRight - treeSize + inRootOffset, inLeft, inRootOffset);
        node->right = buildTree(inorder, postorder, inorderIndexMap, postRight - 1, inLeft + inRootOffset + 1, treeSize - inRootOffset - 1);
        
        return node;
    }
};