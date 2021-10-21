class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> results;
    results.push_back(intervals[0]);
    for (const auto& interval : intervals) {
      auto& last = results.back();
      if (last[1] >= interval[0]) {
        last[1] = max(last[1], interval[1]);
      } else {
        results.push_back(interval);
      }
    }

    return results;
  }
};