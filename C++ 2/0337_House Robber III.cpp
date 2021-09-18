class Solution {
public:
    int rob(TreeNode* root) {
      unordered_map<TreeNode*, int> robMap;
      unordered_map<TreeNode*, int> notRobMap;  
      dfs(root, robMap, notRobMap);

      return max(robMap[root], notRobMap[root]);
    }

  void dfs(TreeNode* node, unordered_map<TreeNode*, int>& robMap, unordered_map<TreeNode*, int>& notRobMap) {
    if (node == nullptr) {
      return;
    }

    dfs(node->left, robMap, notRobMap);
    dfs(node->right, robMap, notRobMap);

    robMap[node] = node->val + notRobMap[node->left] + notRobMap[node->right];
    notRobMap[node] = max(robMap[node->left], notRobMap[node->left]) + max(robMap[node->right], notRobMap[node->right]);
  }
};