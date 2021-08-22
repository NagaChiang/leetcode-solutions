class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> isFounds(nums.size() + 1);
        for (int n : nums) {
            isFounds[n] = true;
        }
        
        for (int i = 0; i <= nums.size(); i++) {
            if (!isFounds[i]) {
                return i;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            missing ^= i ^ nums[i];
        }
        
        return missing;
    }
};

// Slow
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedSum = (nums.size() * (nums.size() + 1)) / 2;
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        
        return expectedSum - sum;
    }
};