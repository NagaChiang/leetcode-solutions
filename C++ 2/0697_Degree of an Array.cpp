class Solution {
public:
  struct NumInfo {
    int count;
    int first;
    int last;

    NumInfo() {
      count = 0;
      first = 0;
      last = 0;
    }

    NumInfo(int c, int f, int l) {
      count = c;
      first = f;
      last = l;
    }
  };

  int findShortestSubArray(vector<int>& nums) {
    int degree = 0;
    unordered_map<int, NumInfo> infoMap;
    for (int i = 0; i < nums.size(); i++) {
      if (infoMap.find(nums[i]) == infoMap.end()) {
        infoMap[nums[i]].count = 0;
        infoMap[nums[i]].first = i;
        infoMap[nums[i]].last = i;
      }

      infoMap[nums[i]].count++;
      infoMap[nums[i]].last = i;
      degree = max(degree, infoMap[nums[i]].count);
    }

    int minLength = INT_MAX;
    for (const auto& [n, info] : infoMap) {
      if (info.count < degree) {
        continue;
      }

      minLength = min(minLength, info.last - info.first + 1);
    }

    return minLength;
  }
};