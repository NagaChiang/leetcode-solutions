class Solution {
public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int total = 0;
    int start = 0;
    int end = -1;
    for (int t : timeSeries) {
      if (t > end) {
        total += end - start + 1;
        start = t;
      }

      end = t + duration - 1;
    }

    total += end - start + 1;

    return total;
  }
};