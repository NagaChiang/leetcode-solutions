class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> minArray;
        findKthMin(root, k, minArray);
        
        return minArray[k - 1];
    }
    
private:
    void findKthMin(TreeNode* node, int k, vector<int>& minArray) {
        if (minArray.size() >= k) {
            return;
        }
        
        if (node == nullptr) {
            return;
        }
        
        findKthMin(node->left, k, minArray);
        minArray.push_back(node->val);
        findKthMin(node->right, k, minArray);
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return getKthNode(root, k)->val;
    }

private:
    TreeNode* getKthNode(TreeNode* node, int& k) {
        if (node == nullptr) {
            return nullptr;
        }

        TreeNode* leftResult = getKthNode(node->left, k);
        if (leftResult != nullptr) {
            return leftResult;
        }

        if (k == 1) {
            return node;
        }

        k--;

        TreeNode* rightResult = getKthNode(node->right, k);

        return rightResult;
    }
};