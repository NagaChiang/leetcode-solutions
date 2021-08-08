class Solution {
public:
    int rob(vector<int>& nums) {     
        int lastLast = 0;
        int last = 0;
        for (int i = 0; i < nums.size(); i++) {
            int current = max(lastLast + nums[i], last);
            lastLast = last;
            last = current;
        }
        
        return last;
    }
};

// DP
class Solution {
public:
    int rob(vector<int>& nums) {     
        vector<int> maxRob(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                maxRob[i] = nums[i];
            } else if (i == 1) {
                maxRob[i] = max(nums[i - 1], nums[i]);
            } else {
                maxRob[i] = max(maxRob[i - 1], nums[i] + maxRob[i - 2]);
            }
        }
        
        return nums.size() > 0 ? maxRob[nums.size() - 1] : 0;
    }
};