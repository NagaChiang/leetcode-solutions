class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) {
            return true;
        }
        
        if (a == nullptr || b == nullptr) {
            return false;
        }
        
        return a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }
};

// KMP
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> array;
        toPreorderArray(root, array);
        
        vector<int> pattern;
        toPreorderArray(subRoot, pattern);
        
        return hasPattern(array, pattern);
    }
    
private:
    void toPreorderArray(TreeNode* node, vector<int>& array) {
        static const int leftNull = INT_MIN;
        static const int rightNull = INT_MAX;
        
        if (node == nullptr) {
            return;
        }
        
        array.push_back(node->val);
        
        if (node->left != nullptr) {
            toPreorderArray(node->left, array);
        } else {
            array.push_back(leftNull);
        }
        
        if (node->right != nullptr) {
            toPreorderArray(node->right, array);
        } else {
            array.push_back(rightNull);
        }
    }
    
    bool hasPattern(vector<int>& array, vector<int> pattern) {
        vector<int> resetIndexMap(pattern.size());
        int i = 1; // resetIndexMap
        int j = 0; // pattern
        while (i < pattern.size()) {
            if (pattern[i] == pattern[j]) {
                j++;
                resetIndexMap[i] = j;
                i++;
            } else {
                if (j > 0) {
                    j = resetIndexMap[j - 1];
                } else {
                    resetIndexMap[i] = 0;
                    i++;
                }
            }
        }
        
        i = 0; // array
        j = 0; // pattern
        while (i < array.size()) {           
            if (array[i] == pattern[j]) {
                i++;
                j++;
            }
            
            if (j == pattern.size()) {
                return true;
            }
            
            if (i < array.size() && array[i] != pattern[j]) {
                if (j > 0) {
                    j = resetIndexMap[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return false;
    }
};