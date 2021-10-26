class Solution {
public:
  int sumNumbers(TreeNode* root) {
    return getSum(root, 0);
  }

  int getSum(TreeNode* node, int parentSum) {
    if (node == nullptr) {
      return 0;
    }

    int sum = node->val + (parentSum * 10);
    if (node->left == nullptr && node->right == nullptr) {
      return sum;
    }

    return getSum(node->left, sum) + getSum(node->right, sum);
  }
};