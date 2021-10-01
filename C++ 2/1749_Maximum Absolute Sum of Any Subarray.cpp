class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int localMin = 0;
        int localMax = 0;
        for (int i = 0; i < nums.size(); i++) {
            localMin = min(localMin, 0) + nums[i];
            localMax = max(localMax, 0) + nums[i];

            maxSum = max(maxSum, -localMin);
            maxSum = max(maxSum, localMax);
        }

        return maxSum;
    }
};