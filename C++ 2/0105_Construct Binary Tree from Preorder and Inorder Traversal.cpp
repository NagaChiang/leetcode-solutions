class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildTree(preorder, inorder, inorderIndexMap, 0, 0, preorder.size());
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderIndexMap, int preStart, int inStart, int treeSize) {
        if (treeSize == 0) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[preStart]);
        int inRootOffset = inorderIndexMap[preorder[preStart]] - inStart;
        node->left = buildTree(preorder, inorder, inorderIndexMap, preStart + 1, inStart, inRootOffset);
        node->right = buildTree(preorder, inorder, inorderIndexMap, preStart + inRootOffset + 1, inStart + inRootOffset + 1, treeSize - inRootOffset - 1);

        return node;
    }
};