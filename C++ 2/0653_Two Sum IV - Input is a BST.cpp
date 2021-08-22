class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> valueSet;
        
        return findTarget(root, k, valueSet);
    }
    
private:
    bool findTarget(TreeNode* node, int k, unordered_set<int>& valueSet) {
        if (node == nullptr) {
            return false;
        }
        
        if (valueSet.find(k - node->val) != valueSet.end()) {
            return true;
        }
        
        valueSet.insert(node->val);
        
        return findTarget(node->left, k, valueSet) || findTarget(node->right, k, valueSet);
    }
};