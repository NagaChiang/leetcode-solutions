/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
    
public:
    
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> avgs;
        
        queue<TreeNode*> q;
        q.push(root);
        int levelNodeNum = q.size();
        int nodeLeft = levelNodeNum;
        long sum = 0;
        while (!q.empty())
        {
            if (nodeLeft == 0)
            {
                avgs.push_back((double)sum / levelNodeNum);
                
                sum = 0;
                levelNodeNum = q.size();
                nodeLeft = levelNodeNum;
            }
            
            TreeNode* node = q.front();
            q.pop();
            nodeLeft--;
            
            sum += node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        avgs.push_back((double)sum / levelNodeNum);
            
        return avgs;
    }
};
