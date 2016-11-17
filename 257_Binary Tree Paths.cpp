#include <vector>
#include <string>

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

	std::vector<std::string> binaryTreePaths(TreeNode* root)
	{
		// NULL
		if(root == NULL)
			return std::vector<std::string>();

		// Leaf
		if(!root->left && !root->right)
		{
			std::vector<std::string> leafPath;
			std::string value = std::to_string(root->val);
			leafPath.push_back(value);
			return leafPath;
		}

		// Add this node to the front of children paths
		std::vector<std::string> leftPaths = binaryTreePaths(root->left);
		std::vector<std::string> rightPaths = binaryTreePaths(root->right);
		addFrontNode(leftPaths, root->val);
		addFrontNode(rightPaths, root->val);

		// Construct return vector
		std::vector<std::string> paths;
		paths.insert(paths.end(), leftPaths.begin(), leftPaths.end());
		paths.insert(paths.end(), rightPaths.begin(), rightPaths.end());
		return paths;
	}

private:

	void addFrontNode(std::vector<std::string>& paths, int value)
	{
		std::string strValue = std::to_string(value);
		for(int i = 0; i < paths.size(); i++)
		{
			// Add to the front
			paths[i].insert(0, strValue + "->");
		}
	}
};