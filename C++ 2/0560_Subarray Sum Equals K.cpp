class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCountMap;
        sumCountMap[0] = 1;
        
        int count = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            // sum[i] - sum[j] = k
            if (sumCountMap.find(sum - k) != sumCountMap.end()) {
                count += sumCountMap[sum - k];
            }
            
            sumCountMap[sum]++;
        }
        
        return count;
    }
};