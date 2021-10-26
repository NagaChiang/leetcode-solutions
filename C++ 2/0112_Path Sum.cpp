class Solution {
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return false;
    }

    int newTarget = targetSum - root->val;
    if (root->left == nullptr && root->right == nullptr) {
      return newTarget == 0;
    }

    if (hasPathSum(root->left, newTarget)) {
      return true;
    }

    return hasPathSum(root->right, newTarget);
  }
};