// Quickselect
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> countMap;
    for (int n : nums) {
      countMap[n]++;
    }
      
    vector<int> values;
    for (const auto& pair : countMap) {
      values.push_back(pair.first);
    }

    vector<int> tops;
    quickSelect(values, 0, values.size() - 1, k, countMap, tops);

    return tops;
  }

  void quickSelect(vector<int>& nums, int low, int high, int k, unordered_map<int, int>& countMap, vector<int>& tops) {
    if (low <= high) {
      int pivot = partition(nums, low, high, countMap);
      if (k < pivot - low + 1) {
        quickSelect(nums, low, pivot - 1, k, countMap, tops);
      } else { // pivot and right part
        for (int i = low; i <= pivot; i++) {
          tops.push_back(nums[i]);
        }

        if (k > pivot - low + 1) {
          quickSelect(nums, pivot + 1, high, k - (pivot - low + 1), countMap, tops);
        }
      }
    }
  }

  int partition(vector<int>& nums, int low, int high, unordered_map<int, int>& countMap) {
    int pivotValue = countMap[nums[high]];
    int i = low;
    for (int j = low; j < high; j++) {
      if (countMap[nums[j]] >= pivotValue) {
        swap(nums[i], nums[j]);
        i++;
      }
    }

    swap(nums[i], nums[high]);
    
    return i;
  }
};

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