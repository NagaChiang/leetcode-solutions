class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int robFirstPrice = robLinear(nums, 2, nums.size() - 2) + nums[0];
        int notRobFirstPrice = robLinear(nums, 1, nums.size() - 1);
        
        return max(robFirstPrice, notRobFirstPrice);
    }
    
    int robLinear(vector<int>& nums, int start, int end) {
        int lastLast = 0;
        int last = 0;
        for (int i = start; i <= end; i++) {
            int current = max(last, lastLast + nums[i]);
            lastLast = last;
            last = current;
        }
        
        return last;
    }    
};