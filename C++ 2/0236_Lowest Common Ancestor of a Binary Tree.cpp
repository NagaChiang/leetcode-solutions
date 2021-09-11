class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool foundP = false;
        bool foundQ = false;

        return dfs(root, p, q, foundP, foundQ);
    }

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q, bool& foundP, bool& foundQ) {
        if (root == nullptr) {
            return nullptr;
        }

        bool foundPInChildren = false;
        bool foundQInChildren = false;

        TreeNode* leftResult = dfs(root->left, p, q, foundPInChildren, foundQInChildren);
        if (leftResult != nullptr) {
            return leftResult;
        }
        
        foundP |= foundPInChildren;
        foundQ |= foundQInChildren;

        foundPInChildren = false;
        foundQInChildren = false;
        TreeNode* rightResult = dfs(root->right, p, q, foundPInChildren, foundQInChildren);
        if (rightResult != nullptr) {
            return rightResult;
        }
        
        foundP |= foundPInChildren || root == p;
        foundQ |= foundQInChildren || root == q;

        if (foundP && foundQ) {
            return root;
        }

        return nullptr;
    }
};