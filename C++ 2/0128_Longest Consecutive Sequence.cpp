// Hash, O(n) but slower
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) {
            numSet.insert(num);
        }
        
        int maxCount = 0;
        for (int num : numSet) {
            if (numSet.find(num - 1) != numSet.end()) {
                continue;
            }
            
            int count = 1;
            int i = num;
            while (numSet.find(i + 1) != numSet.end()) {
                count++;
                i++;
            }
            
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};

// Sort, O(nlogn) but faster
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int count = 1;
        int maxCount = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            
            if (nums[i] == nums[i - 1] + 1) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 1;
            }
        }
            
        return maxCount;
    }
};