// Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > far) {
                return false;
            }
            
            far = max(far, i + nums[i]);
            if (far >= nums.size() - 1) {
                return true;
            }
        }
        
        return false;
    }
};

// DP
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }
        
        vector<bool> canReaches(nums.size());
        canReaches[0] = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (!canReaches[i]) {
                break;
            }
            
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                canReaches[i + j] = true;
            }
            
            if (canReaches[canReaches.size() - 1]) {
                break;
            }
        }
        
        return canReaches[canReaches.size() - 1];
    }
};