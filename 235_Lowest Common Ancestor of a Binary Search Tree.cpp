#include <queue>
#include <limits>

struct TreeNode
{
    int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{

public:

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		// Null check
		if(!root || !p || !q)
			return root;

		// Get big and small value
		int valBig, valSmall;
		if(p->val >= q->val)
		{
			valBig = p->val;
			valSmall = q->val;
		}
		else
		{
			valBig = q->val;
			valSmall = p->val;
		}

		// Search
		TreeNode* node = root;
		while(node)
		{
			if(node->val > valSmall && node->val > valBig)
			{
				// Too big
				node = node->left;
			}
			else if(node->val < valSmall && node->val < valBig)
			{
				// Too small
				node = node->right;
			}
			else
			{
				// Too big
				break;
			}
		}

		return node;
	}
};

// Short ver.
class Solution
{

public:

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		// Null check
		if(!root || !p || !q)
			return root;

		// Search
		TreeNode* node = root;
		while((node->val - p->val) * (node->val - q->val) > 0)
		{
			// Too big or too small
			node = node->val > p->val ? node->left : node->right;
		}

		return node;
	}
};