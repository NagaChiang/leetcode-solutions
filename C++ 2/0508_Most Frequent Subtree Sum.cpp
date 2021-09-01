class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> countMap;
        getTreeSum(root, countMap);

        int maxFreq = INT_MIN;
        vector<int> freqNums;
        for (const auto& pair : countMap) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
                freqNums = {pair.first};
            } else if (pair.second == maxFreq) {
                freqNums.push_back(pair.first);
            }
        }

        return freqNums;
    }

private:
    int getTreeSum(TreeNode* node, unordered_map<int, int>& countMap) {
        if (node == nullptr) {
            return 0;
        }

        int sum = node->val + getTreeSum(node->left, countMap) + getTreeSum(node->right, countMap);
        countMap[sum]++;

        return sum;
    }
};