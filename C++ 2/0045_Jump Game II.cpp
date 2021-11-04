// Greedy
class Solution {
public:
  int jump(vector<int>& nums) {
    int maxReach = 0;
    int end = 0;
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      maxReach = max(maxReach, i + nums[i]);
      if (i == end) {
        end = maxReach;
        count++;
      }
    }

    return count;
  }
};

// DP
class Solution {
public:
  int jump(vector<int>& nums) {
    vector<int> minJumps(nums.size(), INT_MAX);
    minJumps[0] = 0;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
        minJumps[i + j] = min(minJumps[i + j], minJumps[i] + 1);
      }
    }

    return minJumps[nums.size() - 1];
  }
};