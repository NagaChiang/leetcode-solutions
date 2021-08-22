class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        vector<vector<int>> treeValues;
        vector<int> levelValues;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {           
            int levelCount = queue.size();
            for (int i = levelCount; i > 0; i--) {
                TreeNode* node = queue.front();
                queue.pop();
                
                levelValues.push_back(node->val);
                
                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }
            
            treeValues.push_back(levelValues);
            levelValues.clear();
        }
        
        return treeValues;
    }
};