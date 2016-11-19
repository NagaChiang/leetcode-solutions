#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS
class Solution
{

public:

	int minDepth(TreeNode* root)
	{
		if(!root)
			return 0;

		// BFS
		std::queue<TreeNode*> queueNodes;
		queueNodes.push(root);
		int depth = 0;
		int levelSize = 0;
		while(!queueNodes.empty())
		{
			// Check level size
			if(levelSize == 0)
			{
				levelSize = queueNodes.size();
				depth++;
			}

			// Pop
			TreeNode* node = queueNodes.front();
			queueNodes.pop();
			levelSize--;

			// Check leaf
			if(!node->left && !node->right)
			{
				return depth;
			}

			// Push new nodes
			if(node->left)
				queueNodes.push(node->left);
			if(node->right)
				queueNodes.push(node->right);
		}

		return depth;
	}
};