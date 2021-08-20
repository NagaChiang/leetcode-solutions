class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        
        vector<vector<int>> combs;
        for (int i = 0; i < sortedNums.size(); i++) {
            if (i > 0 && sortedNums[i] == sortedNums[i - 1]) {
                continue;
            }
            
            for (int j = i + 1; j < sortedNums.size(); j++) {
                if (j > i + 1 && sortedNums[j] == sortedNums[j - 1]) {
                    continue;
                }
                
                int subTarget = target - sortedNums[i] - sortedNums[j];
                int left = j + 1;
                int right = sortedNums.size() - 1;
                while (left < right) {
                    if (left > j + 1 && sortedNums[left] == sortedNums[left - 1]) {
                        left++;
                        continue;
                    }
                        
                    if (right < sortedNums.size() - 1 && sortedNums[right] == sortedNums[right + 1]) {
                        right--;
                        continue;
                    }
                    
                    int sum = sortedNums[left] + sortedNums[right];
                    if (sum == subTarget) {
                        combs.push_back({sortedNums[i], sortedNums[j], sortedNums[left], sortedNums[right]});
                        left++;
                        right--;
                    } else if (sum > subTarget) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }
        
        return combs;
    }
};

// kSum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        
        return kSum(sortedNums, target, 4);
    }
    
    vector<vector<int>> kSum(vector<int>& nums, int target, int k, int start = 0) {
        if (k < 2) {
            return {};
        }
        
        if (k == 2) {
            return twoSum(nums, target, start);
        }
        
        vector<vector<int>> results;
        for (int i = start; i < nums.size() - (k - 1); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            vector<vector<int>> combs = kSum(nums, target - nums[i], k - 1, i + 1);
            for (const vector<int>& comb : combs) {
                vector<int> c;
                c.push_back(nums[i]);
                c.insert(c.end(), comb.begin(), comb.end());
                results.push_back(c);
            }
        }
        
        return results;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start = 0) {
        vector<vector<int>> pairs;
        int left = start;
        int right = nums.size() - 1;
        while (left < right) {
            if (left > start && nums[left] == nums[left - 1]) {
                left++;
                continue;
            }
            
            if (right < nums.size() - 1 && nums[right] == nums[right + 1]) {
                right--;
                continue;
            }
            
            int sum = nums[left] + nums[right];
            if (sum == target) {
                pairs.push_back({nums[left], nums[right]});
                left++;
                right--;
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        
        return pairs;
    }
};