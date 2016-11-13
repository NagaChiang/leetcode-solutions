#include <stack>

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

	bool isSymmetric(TreeNode* root)
	{
		if(root == NULL)
			return true;

		// DFS
		bool is = true;
		std::stack<TreeNode*> stackLeft;
		std::stack<TreeNode*> stackRight;
		stackLeft.push(root->left);
		stackRight.push(root->right);
		while(!stackLeft.empty() && !stackRight.empty())
		{
			// Pop
			TreeNode* nodeLeft = stackLeft.top();
			TreeNode* nodeRight = stackRight.top();
			stackLeft.pop();
			stackRight.pop();

			// Compare
			if(!nodeLeft && nodeRight
				|| nodeLeft && !nodeRight
				|| nodeLeft && nodeRight && nodeLeft->val != nodeRight->val)
			{
				is = false;
				break;
			}

			// Push new nodes
			if(nodeLeft)
			{
				stackLeft.push(nodeLeft->left);
				stackLeft.push(nodeLeft->right);
			}
			if(nodeRight)
			{
				stackRight.push(nodeRight->right);
				stackRight.push(nodeRight->left);
			}
		}
		
		return is;
	}
};