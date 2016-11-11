#include <stdlib.h>

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

	bool hasPathSum(TreeNode* root, int sum)
	{
		if(root == NULL)
			return false;
		else if(root->left == NULL && root->right == NULL) // Leaf
			return sum == root->val ? true : false;
		else
			return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};