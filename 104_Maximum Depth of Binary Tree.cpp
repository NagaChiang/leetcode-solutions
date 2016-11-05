#include <queue>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive DFS
// 6 ms
class Solution
{

public:

	int maxDepth(TreeNode* root)
	{
		// Check null
		if(root == NULL)
			return 0;

		// Traverse left and right tree
		int depthLeft = maxDepth(root->left);
		int depthRight = maxDepth(root->right);

		// Return the larger one
		return max(depthLeft, depthRight) + 1;
	}
};

// Iterative BFS
// 9 ms
class Solution
{

public:

	int maxDepth(TreeNode* root)
	{
		// Check null
		if(root == NULL)
			return 0;

		// BFS
		int depth = 0;
		int numLevelNodes = 0;
		std::queue<TreeNode*> queueNodes;
		queueNodes.push(root);
		while(!queueNodes.empty())
		{
			// Clear a level
			if(numLevelNodes == 0)
			{
				depth++;
				numLevelNodes = queueNodes.size();
			}

			TreeNode* node = queueNodes.front();
			queueNodes.pop();
			numLevelNodes--;
			if(node->left)
				queueNodes.push(node->left);
			if(node->right)
				queueNodes.push(node->right);
		}

		return depth;
	}
};