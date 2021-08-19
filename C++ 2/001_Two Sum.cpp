class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes;
        unordered_map<int, int> complementMap;
        for (int i = 0; i < nums.size(); i++) {
            if (complementMap.find(nums[i]) != complementMap.end()) {
                indexes.push_back(i);
                indexes.push_back(complementMap[nums[i]]);
                break;
            }
            
            complementMap[target - nums[i]] = i;
        }
        
        return indexes;
    }
};