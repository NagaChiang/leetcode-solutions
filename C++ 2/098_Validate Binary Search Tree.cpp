class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> values;
        addValueInorder(root, values);
        
        for (int i = 1; i < values.size(); i++) {
            if (values[i - 1] >= values[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    void addValueInorder(TreeNode* node, vector<int>& values) {
        if (node == nullptr) {
            return;
        }
        
        addValueInorder(node->left, values);
        values.push_back(node->val);
        addValueInorder(node->right, values);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return checkBst(root, LONG_MIN, LONG_MAX);
    }
    
    bool checkBst(TreeNode* node, long min, long max) {
        if (node == nullptr) {
            return true;
        }
        
        if (min < node->val && node->val < max) {
            return checkBst(node->left, min, node->val) && checkBst(node->right, node->val, max);
        }
        
        return false;
    }
};

// Fast
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return checkBst(root, prev);
    }
    
    bool checkBst(TreeNode* node, TreeNode*& prev) {
        if (node == nullptr) {
            return true;
        }
        
        if (!checkBst(node->left, prev)) {
            return false;
        }
        
        if (prev != nullptr && node->val <= prev->val) {
            return false;
        }
        
        prev = node;
        if (!checkBst(node->right, prev)) {
            return false;
        }
        
        return true;
    }
};