#include <stdlib.h>
#include <algorithm>

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

	bool isBalanced(TreeNode* root)
	{
		return getDepth(root) != -1;
	}

	// return -1 to indicate unbalanced
	int getDepth(TreeNode* root)
	{
		if(!root)
			return 0;

		int left = getDepth(root->left);
		int right = getDepth(root->right);
		if(left == -1 || right == -1 || abs(left - right) > 1)
		{
			return -1;
		}

		return std::max(left, right) + 1;
	}
};

// Very slow
class Solution
{

public:

	bool isBalanced(TreeNode* root)
	{
		if(!root)
			return true;

		// Check this node
		int left = getDepth(root->left);
		int right = getDepth(root->right);
		bool isThis = abs(left - right) <= 1;

		// Check children
		bool isLeft = isBalanced(root->left);
		bool isRight = isBalanced(root->right);

		return isThis && isLeft && isRight;
	}

	int getDepth(TreeNode* root)
	{
		if(!root)
			return 0;

		int left = getDepth(root->left);
		int right = getDepth(root->right);

		return std::max(left, right) + 1;
	}
};