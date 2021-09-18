class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      int maxNum = 0;
      for (int n : nums) {
        maxNum = max(n, maxNum);
      }

      vector<int> sums(maxNum + 1);
      for (int n : nums) {
        sums[n] += n;
      }

      int last2 = 0;
      int last1 = 0;
      for (int i = 0; i < sums.size(); i++) {
        int current = max(last1, last2 + sums[i]);
        last2 = last1;
        last1 = current;
      }

      return last1;
    }
};