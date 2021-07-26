class Solution {
private:
    int maxSum;
    
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }
    
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        int pathSum = node->val + leftGain + rightGain;
        maxSum = max(maxSum, pathSum);
        
        return node->val + max(leftGain, rightGain);
    }
};