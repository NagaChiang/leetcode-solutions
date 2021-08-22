class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> numCounts;
        for (int n : nums) {
            int targetValue = k - n;
            if (numCounts.find(targetValue) != numCounts.end() && numCounts[targetValue] > 0) {
                count++;
                numCounts[targetValue]--;
                continue;
            }
            
            numCounts[n]++;
        }
        
        return count;
    }
};