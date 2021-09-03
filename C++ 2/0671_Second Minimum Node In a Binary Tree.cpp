class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        return findMinLowerBound(root, root->val);
    }

    int findMinLowerBound(TreeNode* node, int lower) {
        if (node == nullptr) {
            return -1;
        }

        if (node->left == nullptr) {
            return node->val > lower ? node->val : -1;
        }

        int leftValue = findMinLowerBound(node->left, lower);
        int rightValue = findMinLowerBound(node->right, lower);

        int result = -1;
        if (leftValue > lower) {
            result = result > 0 ? min(result, leftValue) : leftValue;
        }

        if (rightValue > lower) {
            result = result > 0 ? min(result, rightValue) : rightValue;
        }

        return result;
    }
};