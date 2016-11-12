#include <vector>
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

	std::vector<std::vector<int>> levelOrder(TreeNode* root)
	{
		std::vector<std::vector<int>> vecLevelOrder;

		// Null check
		if(!root)
		{
			return vecLevelOrder;
		}

		// BFS
		std::queue<TreeNode*> queueNodes;
		queueNodes.push(root);
		int levelCountDown = 1;
		std::vector<int> vecLevel;
		while(!queueNodes.empty())
		{
			// Take out a node
			TreeNode* node = queueNodes.front();
			queueNodes.pop();
			levelCountDown--;

			// Store values of each level
			vecLevel.push_back(node->val);

			// Put children into queue
			if(node->left)
				queueNodes.push(node->left);
			if(node->right)
				queueNodes.push(node->right);

			// New level
			if(levelCountDown == 0)
			{
				levelCountDown = queueNodes.size();
				vecLevelOrder.push_back(vecLevel);
				vecLevel = std::vector<int>();
			}
		}

		return vecLevelOrder;
	}
};