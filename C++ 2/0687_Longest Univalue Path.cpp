class Solution {
public:
  int longestUnivaluePath(TreeNode* root) {
    int maxLength = 0;
    getUnivalueLength(root, maxLength);

    return maxLength;
  }

  int getUnivalueLength(TreeNode* node, int& maxLength) {
    if (node == nullptr) {
      return 0;
    }

    int leftLength = getUnivalueLength(node->left, maxLength);
    if (node->left && node->left->val == node->val) {
      leftLength++;
    } else {
      leftLength = 0;
    }

    int rightLength = getUnivalueLength(node->right, maxLength);
    if (node->right && node->right->val == node->val) {
      rightLength++;
    } else {
      rightLength = 0;
    }

    maxLength = max(maxLength, leftLength + rightLength);

    return max(leftLength, rightLength);
  }
};