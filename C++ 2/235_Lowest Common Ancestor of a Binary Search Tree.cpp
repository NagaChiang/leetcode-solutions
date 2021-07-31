class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* big = p->val > q->val ? p : q;
        TreeNode* small = p->val > q->val ? q : p;
        
        TreeNode* node = root;
        while (node != nullptr) {
            if (big->val < node->val) {
                node = node->left;
            } else if (small->val > node->val) {
                node = node->right;
            } else {
                return node;
            }
        }
        
        return nullptr;
    }
};