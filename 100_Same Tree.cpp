#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS
// 3 ms
class Solution
{

public:

	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		std::queue<TreeNode*> queueP;
		std::queue<TreeNode*> queueQ;
		queueP.push(p);
		queueQ.push(q);
		TreeNode* nodeP;
		TreeNode* nodeQ;
		while(!queueP.empty() && !queueQ.empty())
		{
			nodeP = queueP.front();
			nodeQ = queueQ.front();
			queueP.pop();
			queueQ.pop();

			// Both null
			if(!nodeP && !nodeQ)
				continue;

			// One null
			if((!nodeP && nodeQ) || (nodeP && !nodeQ))
				return false;

			// Not the same value
			if(nodeP->val != nodeQ->val)
				return false;

			// Push nodes to the queue
			queueP.push(nodeP->left);
			queueQ.push(nodeQ->left);
			queueP.push(nodeP->right);
			queueQ.push(nodeQ->right);
		}

		return true;
	}
};

// Recursive
// 0 ms
class Solution
{

public:

	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		// Both null
		if(!p && !q)
			return true;

		// One null
		if((!p && q) || (p && !q))
			return false;

		// Both have value
		if(p->val != q->val)
			return false;
		else
		{
			// Check sub trees
			return isSameTree(p->left, q->left)
				&& isSameTree(p->right, q->right);
		}
	}
};