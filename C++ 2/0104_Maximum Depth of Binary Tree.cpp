class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        
        return max(leftMax, rightMax) + 1;
    }
};

// Slow
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int maxDepth = 0;
        unordered_map<TreeNode*, int> depthMap;
        depthMap[root] = 1;
        
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            
            maxDepth = max(maxDepth, depthMap[node]);
            
            if (node->left != nullptr) {
                queue.push(node->left);
                depthMap[node->left] = depthMap[node] + 1;
            }
            
            if (node->right != nullptr) {
                queue.push(node->right);
                depthMap[node->right] = depthMap[node] + 1;
            }
        }
        
        return maxDepth;
    }
};