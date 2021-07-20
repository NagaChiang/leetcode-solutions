class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        TreeNode* left = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(left);
        
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        vector<TreeNode*> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            TreeNode* node = stack.back();
            stack.pop_back();
            
            if (node == nullptr) {
                continue;
            }
            
            swap(node->left, node->right);
            
            stack.push_back(node->left);
            stack.push_back(node->right);
        }
        
        return root;
    }
};