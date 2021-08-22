class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalMax = nums[0];
        int localMin = nums[0];
        int localMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(localMin, localMax);
            }
            
            localMin = min(nums[i], localMin * nums[i]);
            localMax = max(nums[i], localMax * nums[i]);
            globalMax = max(globalMax, localMax);
        }
        
        return globalMax;
    }
};