// Bucket, O(n)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> bucketMap;
        for (int i = 0; i < nums.size(); i++) {
            int id = getBucketId(nums[i], static_cast<long>(t) + 1);
            if (bucketMap.find(id) != bucketMap.end()) {
                return true;
            }
            
            if (bucketMap.find(id + 1) != bucketMap.end() && abs(bucketMap[id + 1] - static_cast<long>(nums[i])) <= t) {
                return true;
            }
            
            if (bucketMap.find(id - 1) != bucketMap.end() && abs(bucketMap[id - 1] - static_cast<long>(nums[i])) <= t) {
                return true;
            }
            
            bucketMap[id] = nums[i];
            if (i >= k) {
                int eraseId = getBucketId(nums[i - k], static_cast<long>(t) + 1);
                bucketMap.erase(eraseId);
            }
        }
        
        return false;
    }
    
private:
    int getBucketId(int num, long width) {
        return num >= 0 ? num / width : ((num + 1) / width) - 1;
    }
};

// Ordered set + lower bound, O(nlog(min(n, k)))
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> numSet;
        for (int i = 0; i < nums.size(); i++) {
            const auto& itr = numSet.lower_bound(static_cast<long>(nums[i]) - t);
            if (itr != numSet.end() && *itr <= static_cast<long>(nums[i]) + t) {
                return true;
            }
            
            numSet.insert(nums[i]);
            if (i >= k) {
                numSet.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};