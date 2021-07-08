class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> maxSubArraySums(nums.size(), 0);
        int maxSum = nums[0];
        maxSubArraySums[0] = maxSum;
        for (int i = 1; i < nums.size(); i++) {
            maxSubArraySums[i] = max(maxSubArraySums[i - 1], 0) + nums[i];
            maxSum = max(maxSum, maxSubArraySums[i]);
        }
        
        return maxSum;
    }
};