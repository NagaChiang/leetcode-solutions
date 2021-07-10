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