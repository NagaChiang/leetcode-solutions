class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> minArray;
        findKthMin(root, k, minArray);
        
        return minArray[k - 1];
    }
    
private:
    void findKthMin(TreeNode* node, int k, vector<int>& minArray) {
        if (minArray.size() >= k) {
            return;
        }
        
        if (node == nullptr) {
            return;
        }
        
        findKthMin(node->left, k, minArray);
        minArray.push_back(node->val);
        findKthMin(node->right, k, minArray);
    }
};