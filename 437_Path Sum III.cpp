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

	// Avoid start from root double times
	int pathSum(TreeNode* root, int sum)
	{
		if(root == NULL)
			return 0;
		else
		{
			// Match
			int match = 0;
			if(sum == root->val)
				match++;

			return match
				+ getPathSum(root->left, sum - root->val, sum)
				+ getPathSum(root->right, sum - root->val, sum);
		}
	}

	int getPathSum(TreeNode* root, int sum, int orgSum)
	{
		if(root == NULL)
			return 0;

		// Match
		int match = 0;
		if(sum == root->val)
			match++;
		if(orgSum == root->val) // New start
			match++;

		return match
			+ getPathSum(root->left, sum - root->val, orgSum)
			+ getPathSum(root->right, sum - root->val, orgSum)
			+ getPathSum(root->left, orgSum - root->val, orgSum)
			+ getPathSum(root->right, orgSum - root->val, orgSum);
	}
};