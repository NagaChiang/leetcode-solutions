class Solution {
  public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int minLength = INT_MAX;
    int sum = 0;
    int start = 0;
    for (int end = 0; end < nums.size(); end++) {
      sum += nums[end];
      while (sum >= target) {
        minLength = min(minLength, end - start + 1);
        sum -= nums[start];
        start++;
      } 
    }

    return minLength < INT_MAX ? minLength : 0;
  }
};