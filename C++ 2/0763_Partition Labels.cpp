// Greedy
class Solution {
public:
  vector<int> partitionLabels(string s) {
    int lasts[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      lasts[s[i] - 'a'] = i;
    }

    vector<int> sizes;
    int start = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++) {
      end = max(end, lasts[s[i] - 'a']);
      if (i == end) {
        sizes.push_back(end - start + 1);
        start = i + 1;
      }
    }
    
    return sizes;
  }
};

// Merge intervals, slow
class Solution {
public:
  vector<int> partitionLabels(string s) {
    static const int charSize = 26;
    static const int elementSize = 2;
    static const int nullIndex = -1;

    vector<vector<int>> intervals(charSize, vector<int>(elementSize, nullIndex));
    for (int i = 0; i < s.size(); i++) {
      auto& interval = intervals[s[i] - 'a'];
      if (interval[0] == nullIndex) {
        interval[0] = i;
        interval[1] = i;
      } else {
        interval[1] = i;
      }
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> results;
    for (const auto& interval : intervals) {
      if (results.size() == 0) {
        if (interval[0] != nullIndex) {
          results.push_back(interval);
        }

        continue;
      }

      auto& last = results.back();
      if (last[1] >= interval[0]) {
        last[1] = max(last[1], interval[1]);
      } else {
        results.push_back(interval);
      }
    }

    vector<int> counts;
    for (const auto& interval : results) {
      counts.push_back(interval[1] - interval[0] + 1);
    }

    return counts;
  }
};