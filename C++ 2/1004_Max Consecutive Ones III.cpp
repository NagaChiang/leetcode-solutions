class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxCount = 0;
        int count = 0;
        for (int start = 0, end = 0; end < nums.size(); end++) {
            if (nums[end] == 1) {
                count++;
            }

            int zeroCount = (end - start + 1) - count;
            if (zeroCount <= k) {
                maxCount = max(maxCount, end - start + 1);
            } else {
                if (nums[start] == 1) {
                    count--;
                }

                start++;
            }
        }

        return maxCount;
    }
};