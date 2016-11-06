struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive DFS
class Solution
{

public:

    int sumOfLeftLeaves(TreeNode* root)
    {
		// Check null
		if(root == NULL)
			return 0;

		// Add left child's value if it's a leaf
		int sum = 0;
		if(root->left)
		{
			// Check leaf
			if(root->left->left == NULL
				&& root->left->right == NULL)
			{
				sum += root->left->val;
			}
			else
			{
				sum += sumOfLeftLeaves(root->left);
			}
		}

		// Calculate subtrees
		sum += sumOfLeftLeaves(root->right);

		return sum;
    }
};