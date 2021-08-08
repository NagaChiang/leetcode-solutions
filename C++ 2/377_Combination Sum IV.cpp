class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> combCounts(target + 1);
        combCounts[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num <= i) {
                    combCounts[i] += combCounts[i - num];
                }
            }
        }
        
        return combCounts[target];
    }
};