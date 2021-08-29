class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int localMax = nums[0];
        int globalMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            localMax = max(localMax, 0) + nums[i];
            globalMax = max(globalMax, localMax);
        }
        
        return globalMax;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        vector<int> maxSumUntil(nums.size());
        maxSumUntil[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxSumUntil[i] = nums[i];
            if (maxSumUntil[i - 1] > 0) {
                maxSumUntil[i] += maxSumUntil[i - 1];
            }
            
            maxSum = max(maxSum, maxSumUntil[i]);
        }
        
        return maxSum;
    }
};