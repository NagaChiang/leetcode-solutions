struct TreeNode
{
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Recursive DFS
class Solution
{

public:

	TreeNode* invertTree(TreeNode* root)
	{
		// Check null
		if(root == NULL)
			return NULL;

		// Swap left and right
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		// Invert subtrees
		invertTree(root->left);
		invertTree(root->right);

		return root;
	}

};