class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int maxScore = 0;
    int score = 0;
    vector<int> indexes(10001, -1);
    for (int left = 0, right = 0; right < nums.size(); right++) {
      if (indexes[nums[right]] >= 0) {
        int newLeft = indexes[nums[right]] + 1;
        for (int i = left; i< newLeft; i++) {
          indexes[nums[i]] = -1;
          score -= nums[i];
        }

        left = newLeft;
      }

      indexes[nums[right]] = right;

      score += nums[right];
      maxScore = max(maxScore, score);
    }

    return maxScore;
  }
};