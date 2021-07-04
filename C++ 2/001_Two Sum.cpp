class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> complementToIndexMap;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            auto itr = complementToIndexMap.find(num);
            if (itr != complementToIndexMap.end()) {
                return {itr->second, i};
            }
            
            complementToIndexMap[target - num] = i;
        }
        
        return {};
    }
};