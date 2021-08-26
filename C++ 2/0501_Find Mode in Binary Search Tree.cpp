class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        int lastValue = INT_MAX;
        int count = 0;
        int maxCount = 0;
        inorder(root, modes, lastValue, count, maxCount);
        
        return modes;
    }
    
    void inorder(TreeNode* node, vector<int>& modes, int& lastValue, int& count, int& maxCount) {
        if (node == nullptr) {
            return;
        }
        
        inorder(node->left, modes, lastValue, count, maxCount);
        
        if (node->val == lastValue) {
            count++;
        } else {
            count = 1;
        }
        
        if (count == maxCount) {
            modes.push_back(node->val);
        } else if (count > maxCount) {
            maxCount = count;
            modes = {node->val};
        }
        
        lastValue = node->val;
        inorder(node->right, modes, lastValue, count, maxCount);
    }
};