class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        vector<vector<int>> triplets;
        for (int i = 0; i < sortedNums.size(); i++) {
            if (sortedNums[i] > 0) {
                break;
            }
            
            if (i > 0 && sortedNums[i - 1] == sortedNums[i]) {
                continue;
            }
            
            int target = -sortedNums[i];
            int left = i + 1;
            int right = sortedNums.size() - 1;
            while (left < right) {
                if (left > i + 1 && sortedNums[left - 1] == sortedNums[left]) {
                    left++;
                    continue;
                }
                
                if (right < sortedNums.size() - 1 && sortedNums[right + 1] == sortedNums[right]) {
                    right--;
                    continue;
                }
                
                int sum = sortedNums[left] + sortedNums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    triplets.push_back({sortedNums[i], sortedNums[left], sortedNums[right]});
                    left++;
                    right--;
                }
            }
        }
        
        return triplets;
    }
};

// Slow
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> tripletSet;
        unordered_set<int> targetNumSet;
        for (int i = 0; i < nums.size(); i++) {
            if (targetNumSet.find(nums[i]) != targetNumSet.end()) {
                continue;
            }
            
            targetNumSet.insert(nums[i]);
            
            int target = -nums[i];
            unordered_set<int> numSet; 
            for (int j = i + 1; j < nums.size(); j++) {
                if (numSet.find(target - nums[j]) != numSet.end()) {
                    vector<int> tri = {nums[i], nums[j], target - nums[j]};
                    sort(tri.begin(), tri.end());
                    tripletSet.insert(tri);
                }
                
                numSet.insert(nums[j]);
            }
        }
        
        vector<vector<int>> triplets(tripletSet.begin(), tripletSet.end());
        
        return triplets;
    }
};