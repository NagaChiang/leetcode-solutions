class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == k) {
            return nums;
        }
        
        unordered_map<int, int> countMap;
        for (int n : nums) {
            countMap[n]++;
        }
        
        priority_queue<pair<int,int>> heap;
        for (auto pair : countMap) {
            heap.push({pair.second, pair.first});
        }
        
        vector<int> topNums(k);
        for (int i = 0; i < k; i++) {
            topNums[i] = heap.top().second;
            heap.pop();
        }
        
        return topNums;
    }
};